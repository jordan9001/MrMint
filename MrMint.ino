#include <SPI.h>
#include <Wire.h>
#include <cstdint>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "art.h"
#include "leds.h"

// PIN LAYOUT
#define SOIL    A7  // 21, Analog read
#define SPEAKER 20
#define OLEDSCL 19
#define OLEDSDA 18
//#define LEDCTRL 17  // To WS2812 line
#define UVCTRL  16  // To relay
#define BTN     9   // push button

// screen
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_HEADER 16

#define SHOWTICKS_PAU 3
#define SHOWTICKS_SEC 6
#define SHOWTICKS_MIN 4
#define SHOWTICKS_HR  4
#define SHOWTICKS_WK  4

#define HOLD_MILLI    3300
#define MILLI1HR      (1000 * 60 * 60)
#define MILLI12HR     (MILLI1HR * 12)
#define MILLI3HR      (MILLI1HR * 3)


// config
#define TEENSY_ARES 15
#define TEENSY_BAUD 0 // ignored, uses USB

#define LOOP_DELAY  300

#define MAXA        0x7fff
#define MINA        0x0
#define WET         MAXA
#define DRY         9000
#define DRYBEEP     12000

#define MTICKMOD    60
#define HTICKMOD    60

#define SARRSZ      SCREEN_WIDTH
#define MARRSZ      SCREEN_WIDTH
#define HARRSZ      (24*7*2)

#define BEEPTIME    (1500)
#define BEEPFREQ    666

// Globals data lists
uint16_t secondData[SARRSZ];
uint16_t minuteData[MARRSZ];
uint16_t hourData[HARRSZ];
size_t secondCursor = 0;
size_t minuteCursor = 0;
size_t hourCursor = 0;

uint32_t runningSecondAvg = 0;
uint32_t runningMinuteAvg = 0;

size_t tick = 0;
int uvon = 0;
bool dobeep = false;

IntervalTimer tmr;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

enum graphstate {gpause, gsec, gmin, ghrs, gwek};

void setup() {
  pinMode(BTN, INPUT);
  pinMode(UVCTRL, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  Serial.begin(TEENSY_BAUD);
  
  delay(300);
  Serial.println("Starting MrMint");

  ledsetup();
  
  analogReadResolution(TEENSY_ARES);
  
  

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;); // loop forever
  }

  display.clearDisplay();
  delay(1500);
  DRAWBMP(MRMINT);
  DRAWBMP(LEAVES);
  display.display();
  delay(600);
  // start timer interrupt
  tmr.begin(updateSoil, 1000000);
}

void updateSoil() {
  uint16_t aval = analogRead(SOIL);

  tick++;

  secondData[secondCursor] = aval;
  runningSecondAvg += aval;
  
  secondCursor++;
  if (secondCursor >= SARRSZ) {
    secondCursor = 0;
  }

  if (!(tick % 60)) {
    aval = runningSecondAvg / MTICKMOD;
    runningSecondAvg = 0;
    minuteData[minuteCursor] = aval;
    runningMinuteAvg += aval;

    // beep if we are too dry
    if (aval < DRYBEEP) {
      dobeep = true;
    }

    minuteCursor++;
    if (minuteCursor >= MARRSZ) {
      minuteCursor = 0;
    }

    if (!(tick % (MTICKMOD * HTICKMOD))) {
      aval = runningMinuteAvg / HTICKMOD;
      runningMinuteAvg = 0;
      hourData[hourCursor] = aval;

      hourCursor++;
      if (hourCursor >= HARRSZ) {
        hourCursor = 0;
      }
    }
  }
}

void drawArr(int c, uint16_t* arr, size_t arrsz, int skip) {
  int x;
  int y;

  display.fillRect(0, SCREEN_HEADER, display.width(), display.height()-SCREEN_HEADER, SSD1306_BLACK);
  
  for (x = SCREEN_WIDTH-1; x >= 0; x--) {
    if (c <= 0) {
      c = arrsz;
    }
    c -= skip;

    y = constrain(map(arr[c], DRY, WET, SCREEN_HEADER, SCREEN_HEIGHT-1), SCREEN_HEADER, SCREEN_HEIGHT-1);
    
    display.drawPixel(x, y, SSD1306_WHITE);
  }
  display.display();
}

void drawSeconds() {
  // update header
  display.fillRect(0, 0, display.width(), SCREEN_HEADER, SSD1306_BLACK);
  DRAWBMP(SOIL);
  DRAWBMP(SEC);
  drawArr(secondCursor, secondData, SARRSZ, 1);
}

void drawMinutes() {
  // update header
  display.fillRect(0, 0, display.width(), SCREEN_HEADER, SSD1306_BLACK);
  DRAWBMP(SOIL);
  DRAWBMP(MIN);
  drawArr(minuteCursor, minuteData, MARRSZ, 1);
}

void drawHours() {
  // update header
  display.fillRect(0, 0, display.width(), SCREEN_HEADER, SSD1306_BLACK);
  DRAWBMP(SOIL);
  DRAWBMP(HR);
  drawArr(hourCursor, hourData, HARRSZ, 1);
}

void drawWeek() {
  // update header
  display.fillRect(0, 0, display.width(), SCREEN_HEADER, SSD1306_BLACK);
  DRAWBMP(SOIL);
  DRAWBMP(WEEK);
  drawArr(hourCursor, hourData, HARRSZ, 2);
}

void loop() {
  static size_t prevtick = 0;
  static graphstate gs = gsec;
  static int gtick = 6;
  static int lastbtn = 0;
  static elapsedMillis btnHold = 0;
  static elapsedMillis light12hr = 0;
  static elapsedMillis uvtimer = 0;
  static bool holdhappened = false;
  int btn = 0;
  
  if (prevtick != tick) {
    prevtick = tick;    

    switch (gs) {
    case gpause:
      break;
    case gsec:
      drawSeconds();
      break;
    case gmin:
      drawMinutes();
      break;
    case ghrs:
      drawHours();
      break;
    case gwek:
      drawWeek();
      break;
    }
    
    gtick -= 1;
    if (gtick <= 0) {
      switch (gs) {
      
      case gsec:
        gs = gmin;
        gtick = SHOWTICKS_MIN;
        break;
      case gmin:
        gs = ghrs;
        gtick = SHOWTICKS_HR;
        break;
      case ghrs:
        gs = gwek;
        gtick = SHOWTICKS_WK;
        break;
      case gpause:
        // fall through
      case gwek:
        gs = gsec;
        gtick = SHOWTICKS_SEC;
        break;
      }
    }
  }

  // tick led's
  ledstick();
  
  // handle button press, sound, etc
  if (dobeep) {
    dobeep = false;
    tone(SPEAKER, BEEPFREQ, BEEPTIME);
  }
  
  // if button is pressed
  btn = digitalRead(BTN);  
  if (btn != lastbtn) {
    lastbtn = btn;

    if (btn == HIGH) {
      // button pressed
      btnHold = 0;
      holdhappened = false;
    } else if (btn == LOW && !holdhappened){
      // button released
      // change lights
      display.clearDisplay();
      DRAWBMP(SUN);
      
      switch (lst) {
      case ledsoff:
        lst = ledsspin;
        DRAWBMP(SWISH);
        break;
      case ledsspin:
        if (uvon == LOW) {
          uvon = HIGH;
          digitalWrite(UVCTRL, uvon);
          DRAWBMP(SWISHUV);
        } else {
          uvon = LOW;
          digitalWrite(UVCTRL, uvon);
          lst = ledson;
          DRAWBMP(ON);
        }
        break;
      case ledson:
        if (uvon == LOW) {
          uvon = HIGH;
          digitalWrite(UVCTRL, uvon);
          DRAWBMP(ONUV);
        } else {
          uvon = LOW;
          digitalWrite(UVCTRL, uvon);
          lst = ledsoff;
          DRAWBMP(OFF);
        }
        break;
      }

      // allow new header to stay for a bit
      DRAWBMP(LEAVES);
      display.display();
      gs = gpause;
      gtick = SHOWTICKS_PAU;
    }
  } else if (btn == HIGH && btnHold > HOLD_MILLI) {
    holdhappened = true;
    // do long hold stuff
    //long press to start or stop light for 12 hr
    light12hr = MILLI12HR;
  }

  // check if it is time to turn on/off lights
  if (light12hr >= MILLI12HR) {
    light12hr = 0;
    uvtimer = 0;
    if (lst != ledsoff) {
      uvon = LOW;
      digitalWrite(UVCTRL, uvon);
      lst = ledsoff;
    } else {
      lst = ledsspin;
    }
  }

  if (lst != ledsoff) {
    if (uvon == HIGH && uvtimer > MILLI1HR) {
      uvon = LOW;
      digitalWrite(UVCTRL, uvon);
      uvtimer = 0;
    } else if (uvon == LOW && uvtimer > MILLI3HR) {
      uvon = HIGH;
      digitalWrite(UVCTRL, uvon);
      uvtimer = 0;
    }
  }
  
  delay(150);
}
