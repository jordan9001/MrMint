#ifndef LEDS_H
#define LEDS_H

#define LEDCTRL 17  // To WS2812 line

enum ledstate {ledsoff, ledsspin, ledson};
extern ledstate lst;

void ledsetup();

void ledstick();

#endif
