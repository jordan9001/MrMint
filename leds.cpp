#include <cstdint>
#include <Adafruit_NeoPixel.h>
#include "leds.h"

#define NUMLEDS     18
#define SHIFTAMT    12
#define SHIFTONE    (1 << SHIFTAMT)
#define SHIFTMASK   (~(SHIFTONE - 1))
#define PTRAD       (3 << SHIFTAMT)
#define ROTATEPT    (NUMLEDS << SHIFTAMT)
#define HALFROTATE  (ROTATEPT>>1)
#define MAXVEL      ((1<<SHIFTAMT)/3)
#define MAXACCEL    (MAXVEL / 15)
#define TIMESCALE   45

struct color { // uint16 so we can add things together then ceil it
  uint16_t r;
  uint16_t g;
  uint16_t b;
};

struct colorpt {
  int32_t pos;
  int32_t vel;
  color c;
};

// colorpt will randomly walk towards one of these every tick
color coloredges[] = {
  {0xff, 0xff, 0xff},
  {0xff, 0xff, 0x00},
  {0x00, 0xff, 0x00},
  {0x00, 0x00, 0xff},
  {0x00, 0xff, 0xdd},
};
#define NUMEDGES  5

colorpt pts[] = {
  {
    ((0 * NUMLEDS) << SHIFTAMT) / 5,
    0,
    coloredges[0],
  },
  {
    ((1 * NUMLEDS) << SHIFTAMT) / 5,
    0,
    coloredges[1],
  },
  {
    ((2 * NUMLEDS) << SHIFTAMT) / 5,
    0,
    coloredges[2],
  },
  {
    ((3 * NUMLEDS) << SHIFTAMT) / 5,
    0,
    coloredges[3],
  },
  {
    ((4 * NUMLEDS) << SHIFTAMT) / 5,
    0,
    coloredges[4],
  },
};
#define NUMPTS  5

Adafruit_NeoPixel leds(NUMLEDS, LEDCTRL, NEO_GRB + NEO_KHZ800);
ledstate lst = ledsoff;
color ledarr[NUMLEDS];

void genledarr() {
  uint16_t p;
  int32_t pos;
  int32_t ppos;
  int32_t rpos;
  int32_t rd;
  uint32_t r;
  uint32_t g;
  uint32_t b;
  int i;
  // clear arr
  memset(ledarr, 0, sizeof(ledarr));

  // add each pt in
  for (i = 0; i < NUMPTS; i++) {
    ppos = pts[i].pos;
    for (pos = ((ppos - PTRAD) & SHIFTMASK); pos <= (ppos + PTRAD); pos += SHIFTONE) {
      // linear drop off is c * (r-d) / r
      // do it twice for sharper falloff
      rd = PTRAD - abs(pos - ppos);
      if (rd <= 0) {
        continue;
      }

      r = pts[i].c.r;
      g = pts[i].c.g;
      b = pts[i].c.b;
      r *= rd;
      r /= PTRAD;
      r *= rd;
      r /= PTRAD;
      
      g *= rd;
      g /= PTRAD;
      g *= rd;
      g /= PTRAD;
      
      b *= rd;
      b /= PTRAD;
      b *= rd;
      b /= PTRAD;

      rpos = pos;
      if (rpos < 0) {
        rpos += ROTATEPT;
      }
      if (rpos >= ROTATEPT) {
        rpos -= ROTATEPT;
      }

      p = rpos>>SHIFTAMT;

      ledarr[p].r += r;
      ledarr[p].g += g;
      ledarr[p].b += b;
    }
  }
}

void walkpts() {
  int i;
  int32_t a;
  static elapsedMillis dt = 0;
  int32_t pos;
  int32_t dpos;
  int32_t dvel;

  for (i = 0; i < NUMPTS; i++) {
    // random move color
    //TODO move towards the chosen color at the chosen pace
    //TODO if we get there, then choose another from the list
    //colormovetowards(pts[i].c, coloredges[random(NUMEDGES)], &nextcolor, random(MAXCOLORSTEP))

    // random accel
    a = random(MAXACCEL * 2) - MAXACCEL;
    // we need to account for a / dt here
    dvel = a * TIMESCALE / ((int32_t)dt);
    pts[i].vel += dvel;

    if (pts[i].vel > MAXVEL) {
      pts[i].vel = MAXVEL;
    } else if (pts[i].vel < -MAXVEL) {
      pts[i].vel = -MAXVEL;
    }

    // apply vel
    pos = pts[i].pos;
    dpos = pts[i].vel * TIMESCALE / ((int32_t)dt);
    pos += dpos;
    if (pos < 0) {
      pos += ROTATEPT;
    } else if (pos > ROTATEPT) {
      pos -= ROTATEPT;
    }

    pts[i].pos = pos;
    
  }
  genledarr();

  dt = 0;
}

void ledsetup() {
  Serial.print("MAXVEL ");
  Serial.print(MAXVEL, HEX);
  Serial.print(" MAXACC ");
  Serial.print(MAXACCEL, HEX);
  Serial.println();
  genledarr();
  leds.begin();
}

void ledstick() {
  static ledstate prevlst = ledson;
  uint16_t i;
  if (prevlst != lst) {
    // state changed
    prevlst = lst;
    switch (lst) {
    case ledsoff:
      leds.clear();
      leds.show();
      break;
    case ledsspin:
      // we could like start a fade in here
      // fall through
    case ledson:
      // restore from the array
      goto UPDATEPX;
    }
    return;
  }

  // continue state
  if (lst == ledsoff) {
    return;
  } else if (lst == ledson) {
    return;
  }

  // let the loop walk
  walkpts();
  
 UPDATEPX:
  // draw from array
  for (i = 0; i < NUMLEDS; i++) {
    if (ledarr[i].r > 0xff) {
      ledarr[i].r = 0xff;
    }
    if (ledarr[i].g > 0xff) {
      ledarr[i].g = 0xff;
    }
    if (ledarr[i].b > 0xff) {
      ledarr[i].b = 0xff;
    }
    leds.setPixelColor(i, (uint8_t)ledarr[i].r, (uint8_t)ledarr[i].g, (uint8_t)ledarr[i].b);
  }
  leds.show();
}
