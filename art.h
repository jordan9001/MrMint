#ifndef ART_H
#define ART_H

// Macros
#define DRAWBMP(x)  display.drawBitmap(x ## _X, x ## _Y, x ## _BMP, x ## _W, x ## _H, SSD1306_WHITE)

// ART
#define LEAVES_H  42
#define LEAVES_W  51
#define LEAVES_X  8
#define LEAVES_Y  19
static const unsigned char PROGMEM LEAVES_BMP[] = {
B00000000,B00000000,B00000000,B01100000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B01111100,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B01111110,B01100000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111111,B01110000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111110,B11111010,B00000000,B00000000,
B00000000,B00000000,B00000001,B11111111,B11111110,B00000000,B00000000,
B00000000,B00000000,B00000001,B11111111,B01111101,B00000000,B00000000,
B00000000,B00000000,B00000001,B11111111,B11111101,B00000000,B00000000,
B00000000,B00000000,B00000001,B10111111,B11110111,B00000000,B00000000,
B00000000,B00000000,B00001001,B11011111,B11111111,B11100000,B00000000,
B00000000,B00000000,B00000111,B11101111,B11111111,B01100000,B00000000,
B00000000,B00000000,B00001101,B10111111,B11111111,B01111000,B00000000,
B00000000,B00000000,B00001111,B10111110,B11111011,B11111000,B00000000,
B00000000,B00000000,B00000111,B11011111,B01111011,B11110110,B00000000,
B00000000,B00000000,B00000110,B11101111,B11111111,B11110110,B00000000,
B00000000,B00000000,B00000111,B01110111,B01111111,B10111010,B00000000,
B00000000,B00001111,B11110111,B11111001,B11111111,B10111010,B00000000,
B00000000,B00111111,B11111011,B10111110,B00111111,B11111111,B10000000,
B00000000,B11111111,B11111011,B11111111,B11111111,B11111111,B10000000,
B00000111,B11111111,B11110111,B11110111,B11011111,B11111111,B11000000,
B00011111,B11111111,B11110111,B11111111,B11001111,B11111111,B10000000,
B00111111,B11111111,B11110111,B11111110,B11101111,B11111111,B11000000,
B01111111,B11111111,B11111011,B11111110,B11110111,B11111110,B01000000,
B11111000,B11111111,B11111001,B11111111,B11111111,B11111111,B11000000,
B01111110,B01011111,B11111101,B11111111,B11111111,B11111111,B11000000,
B00111111,B11111011,B01111101,B11001111,B11111011,B11111111,B11000000,
B00111111,B11111111,B11101101,B11111111,B11111111,B11111111,B11100000,
B00011111,B11100111,B11110001,B01111110,B11111111,B11111111,B11100000,
B00011111,B01001111,B11111000,B00111111,B11111101,B11111111,B11000000,
B00001111,B11111111,B11111111,B00111111,B11111101,B11111111,B11000000,
B00000111,B11111111,B11111111,B01111111,B11111110,B11111111,B11000000,
B00000011,B11111111,B11111111,B10111111,B11111110,B11111111,B11000000,
B00000011,B11111111,B11111111,B11000111,B00111111,B01111111,B10000000,
B00000000,B11111111,B11111111,B11110111,B11001111,B01111111,B10000000,
B00000000,B01111111,B11111111,B11110111,B00111111,B10111111,B00000000,
B00000000,B11111111,B11111111,B11111001,B11111111,B10111000,B00000000,
B00000000,B00111111,B11111111,B11111100,B11111111,B10011000,B00000000,
B00000000,B00001111,B11111111,B11111110,B01111111,B10000000,B00000000,
B00000000,B00001111,B11111111,B11111110,B00000011,B00000000,B00000000,
B00000000,B00000001,B11111111,B11111111,B00000000,B00000000,B00000000,
B00000000,B00000000,B11111111,B11111111,B11111110,B00000000,B00000000,
B00000000,B00000000,B00000001,B00111111,B11110000,B00000000,B00000000
};


#define WATERME_H 38
#define WATERME_W 62
#define WATERME_X 64
#define WATERME_Y 21
static const unsigned char PROGMEM WATERME_BMP[] = {
B00011110,B00011100,B00111100,B00000000,B00000000,B00000000,B00000000,B00000000,
B00011110,B00111110,B00111100,B00000000,B01111000,B00000000,B00000000,B00000000,
B00001110,B00111110,B00111000,B00000000,B01111000,B00000000,B00000000,B00000000,
B00001110,B00111110,B01111000,B00000000,B01111000,B00000000,B00000000,B00000000,
B00001111,B00111110,B01111001,B11111100,B11111100,B00111110,B00011101,B11000000,
B00001111,B00110110,B01110011,B11111110,B11111100,B11111111,B00011111,B11000000,
B00000111,B01110111,B01110011,B11111110,B01111000,B11110111,B10011111,B11000000,
B00000111,B01110111,B01110011,B10001110,B01111001,B11100011,B10011110,B00000000,
B00000111,B01110111,B01110000,B01111110,B01111001,B11111111,B11011100,B00000000,
B00000011,B11100111,B11100011,B11111110,B01111001,B11111111,B11011100,B00000000,
B00000011,B11100011,B11100011,B11001110,B01111001,B11100000,B00011100,B00000000,
B00000011,B11100011,B11100111,B10001110,B01111001,B11100001,B10011100,B00000000,
B00000011,B11100011,B11100111,B11111110,B01111000,B11110111,B10011100,B00000000,
B00000001,B11100011,B11000011,B11111110,B00111100,B11111111,B10011100,B00000000,
B00000001,B11000001,B11000001,B11101111,B00111100,B00111110,B00011100,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B11111000,B00111110,B00000000,B00000000,B00111111,B11110001,B11000000,B00000000,
B11111000,B01111110,B00000000,B00000000,B00111111,B11111001,B11000000,B00000000,
B11111100,B01111110,B00000000,B00000000,B00111111,B11111101,B11000000,B00000000,
B11111100,B01111110,B00000000,B00000000,B00111100,B00111101,B11000000,B00000000,
B11111100,B01111110,B00011111,B00000000,B00111100,B00111101,B11001111,B11111000,
B11111100,B01111110,B01111111,B10000000,B00111100,B00111101,B11001111,B11111000,
B11111110,B11111110,B01111011,B11000000,B00111100,B01111101,B11000111,B11111000,
B11111110,B11111110,B11110001,B11000000,B00111111,B11111001,B11000000,B11110000,
B11111110,B11111110,B11111111,B11100000,B00111111,B11110001,B11000000,B11110000,
B11111110,B11011110,B11111111,B11100000,B00111111,B11100001,B11000001,B11100000,
B11110111,B11011110,B11110000,B00000000,B00111100,B00000001,B11000011,B11000000,
B11110111,B11011110,B11110000,B11000000,B00111100,B00000001,B11000111,B10000000,
B11110111,B11011110,B01111011,B11000000,B00111100,B00000001,B11001111,B11111000,
B11110111,B11011110,B01111111,B11000000,B00111100,B00000001,B11001111,B11111100,
B11110011,B10011110,B00011111,B00000000,B00111100,B00000001,B11001111,B11111100
};

#define SOIL_H  14
#define SOIL_W  43
#define SOIL_X  10
#define SOIL_Y  1
static const unsigned char PROGMEM SOIL_BMP[] = {
B00000000,B00000000,B00000000,B00000001,B11100000,B00000000,
B00011111,B11000000,B00000000,B01111001,B11100000,B00000000,
B01111111,B11100000,B00000000,B01111001,B11100000,B00000000,
B01111000,B11100000,B00000000,B00000001,B11100000,B00000000,
B11110000,B01100001,B11111000,B01111001,B11100001,B11100000,
B01111100,B00000111,B11111100,B01111001,B11100001,B11100000,
B01111111,B10000111,B10111100,B01111001,B11100001,B11100000,
B01111111,B11001111,B00011110,B01111001,B11100000,B00000000,
B00011111,B11101111,B00011110,B01111001,B11100000,B00000000,
B00000011,B11101111,B00011110,B01111001,B11100000,B00000000,
B11000001,B11101111,B00011110,B01111001,B11100000,B00000000,
B11110001,B11100111,B10111100,B01111001,B11100001,B11100000,
B11111111,B11000111,B11111100,B01111001,B11100001,B11100000,
B01111111,B10000001,B11111000,B01111001,B11100001,B11100000
};


#define SUN_H 13
#define SUN_W 43
#define SUN_X 10
#define SUN_Y 2
static const unsigned char PROGMEM SUN_BMP[] = {
B00011111,B11000000,B00000000,B00000000,B00000000,B00000000,
B01111111,B11100000,B00000000,B00000000,B00000000,B00000000,
B01111000,B11100000,B00000000,B00000000,B00000000,B00000000,
B11110000,B01100111,B00011110,B00111111,B11000001,B11100000,
B01111100,B00000111,B00011110,B00111111,B11100001,B11100000,
B01111111,B10000111,B00011110,B00111111,B11110001,B11100000,
B01111111,B11000111,B00011110,B00111100,B11110000,B00000000,
B00011111,B11100111,B00011110,B00111100,B11110000,B00000000,
B00000011,B11100111,B10011110,B00111100,B11110000,B00000000,
B11000001,B11100111,B10011110,B00111100,B11110000,B00000000,
B11110001,B11100111,B11111110,B00111100,B11110001,B11100000,
B11111111,B11000111,B11111110,B00111100,B11110001,B11100000,
B01111111,B10000011,B11111110,B00111100,B11110001,B11100000
};


#define MRMINT_H  14
#define MRMINT_W  67
#define MRMINT_X  31
#define MRMINT_Y  1
static const unsigned char PROGMEM MRMINT_BMP[] = {
B11111000,B00111110,B00000000,B00001111,B10000011,B11100000,B00000000,B00000000,B00000000,
B11111000,B00111110,B00000000,B00001111,B10000011,B11101111,B00000000,B00001111,B00000000,
B11111100,B01111110,B00000000,B00001111,B11000111,B11101111,B00000000,B00001111,B00000000,
B11111100,B01111110,B00000000,B00001111,B11000111,B11100000,B00000000,B00001111,B00000000,
B11111110,B11111110,B11111111,B00001111,B11101111,B11101111,B01111111,B11011111,B11100000,
B11111110,B11111110,B11111111,B00001111,B11101111,B11101111,B01111111,B11111111,B11100000,
B11111111,B11111110,B11111111,B00001111,B11111111,B11101111,B01111111,B11101111,B00000000,
B11111111,B11011110,B11110000,B00001111,B11111101,B11101111,B01111001,B11101111,B00000000,
B11110111,B11011110,B11110000,B00001111,B01111101,B11101111,B01111001,B11101111,B00000000,
B11110111,B10011110,B11110000,B00001111,B01111001,B11101111,B01111001,B11101111,B00000000,
B11110011,B10011110,B11110000,B00001111,B00111001,B11101111,B01111001,B11101111,B00000000,
B11110000,B00011110,B11110000,B00001111,B00000001,B11101111,B01111001,B11101111,B00000000,
B11110000,B00011110,B11110000,B00001111,B00000001,B11101111,B01111001,B11100111,B11100000,
B11110000,B00011110,B11110000,B00001111,B00000001,B11101111,B01111001,B11100111,B11100000
};


#define SEC_H 13
#define SEC_W 34
#define SEC_X 58
#define SEC_Y 2
static const unsigned char PROGMEM SEC_BMP[] = {
B00011111,B11000000,B00000000,B00000000,B00000000,
B01111111,B11100000,B00000000,B00000000,B00000000,
B01111000,B11100000,B00000000,B00000000,B00000000,
B11110000,B01100001,B11111000,B00011111,B10000000,
B01111100,B00000111,B11111100,B01111111,B11000000,
B01111111,B10000111,B10111100,B01111001,B11000000,
B01111111,B11001111,B00011100,B11110000,B00000000,
B00011111,B11101111,B11111110,B11110000,B00000000,
B00000011,B11101111,B11111110,B11110000,B00000000,
B11000001,B11101111,B00000000,B11110000,B00000000,
B11110001,B11100111,B10001100,B01111001,B11000000,
B11111111,B11000111,B11111100,B01111111,B11000000,
B01111111,B10000001,B11111100,B00011111,B10000000
};


#define MIN_H 13
#define MIN_W 33
#define MIN_X 57
#define MIN_Y 2
static const unsigned char PROGMEM MIN_BMP[] = {
B11111000,B01111100,B01111000,B00000000,B00000000,
B11111000,B01111100,B01111000,B00000000,B00000000,
B11111100,B01111100,B00000000,B00000000,B00000000,
B11111100,B11111100,B01111001,B11111110,B00000000,
B11111100,B11111100,B01111001,B11111111,B00000000,
B11111111,B11111100,B01111001,B11111111,B10000000,
B11111111,B11111100,B01111001,B11100111,B10000000,
B11111111,B10111100,B01111001,B11100111,B10000000,
B11110111,B10111100,B01111001,B11100111,B10000000,
B11110111,B10111100,B01111001,B11100111,B10000000,
B11110000,B00111100,B01111001,B11100111,B10000000,
B11110000,B00111100,B01111001,B11100111,B10000000,
B11110000,B00111100,B01111001,B11100111,B10000000
};


#define HR_H  13
#define HR_W  22
#define HR_X  58
#define HR_Y  2
static const unsigned char PROGMEM HR_BMP[] = {
B11110000,B11110000,B00000000,
B11110000,B11110000,B00000000,
B11110000,B11110000,B00000000,
B11110000,B11110001,B11111100,
B11110000,B11110001,B11111100,
B11111111,B11110001,B11111100,
B11111111,B11110001,B11100000,
B11110000,B11110001,B11100000,
B11110000,B11110001,B11100000,
B11110000,B11110001,B11100000,
B11110000,B11110001,B11100000,
B11110000,B11110001,B11100000,
B11110000,B11110001,B11100000
};


#define WEEK_H  14
#define WEEK_W  55
#define WEEK_X  61
#define WEEK_Y  1
static const unsigned char PROGMEM WEEK_BMP[] = {
B00000000,B00000000,B00000000,B00000000,B00000000,B00000111,B10000000,
B11110001,B11100001,B11000000,B00000000,B00000000,B00000111,B10000000,
B11110001,B11110011,B11000000,B00000000,B00000000,B00000111,B10000000,
B01110001,B11110011,B11000000,B00000000,B00000000,B00000111,B10000000,
B01111011,B11110011,B11000001,B11111000,B00011111,B10000111,B10111110,
B01111011,B11110011,B10000111,B11111100,B01111111,B11000111,B10111100,
B01111011,B11111111,B10000111,B10111100,B01111011,B11000111,B11111000,
B00111011,B11111111,B10001111,B00011100,B11110001,B11000111,B11110000,
B00111111,B10111111,B10001111,B11111110,B11111111,B11100111,B11110000,
B00111111,B10111111,B00001111,B11111110,B11111111,B11100111,B11110000,
B00111111,B00111111,B00001111,B00000000,B11110000,B00000111,B11111000,
B00011111,B00111111,B00000111,B10001100,B01111000,B11000111,B10111100,
B00011111,B00011111,B00000111,B11111100,B01111111,B11000111,B10111100,
B00011111,B00011110,B00000001,B11111100,B00011111,B11000111,B10011110
};


#define OFF_H 14
#define OFF_W 31
#define OFF_X 56
#define OFF_Y 1
static const unsigned char PROGMEM OFF_BMP[] = {
B00000000,B00000000,B00111110,B00111110,
B00001111,B11000000,B01111110,B01111110,
B00111111,B11110000,B11110000,B11110000,
B01111100,B11110000,B11110000,B11110000,
B01111000,B01111001,B11111101,B11111100,
B01111000,B01111001,B11111101,B11111100,
B11110000,B00111000,B11110000,B11110000,
B11110000,B00111100,B11110000,B11110000,
B11110000,B00111000,B11110000,B11110000,
B01111000,B01111000,B11110000,B11110000,
B01111000,B01111000,B11110000,B11110000,
B01111100,B11110000,B11110000,B11110000,
B00111111,B11110000,B11110000,B11110000,
B00001111,B11000000,B11110000,B11110000
};


#define SWISH_H 11
#define SWISH_W 25
#define SWISH_X 58
#define SWISH_Y 4
static const unsigned char PROGMEM SWISH_BMP[] = {
B00001111,B11100000,B00001111,B10000000,
B00011111,B11111000,B00001111,B10000000,
B00111111,B11111100,B00001111,B10000000,
B00111111,B11111110,B00001111,B10000000,
B01111111,B11111111,B00001111,B10000000,
B01111110,B01111111,B10011111,B10000000,
B01111100,B00111111,B11111111,B00000000,
B11111100,B00011111,B11111111,B00000000,
B11111000,B00001111,B11111110,B00000000,
B11111000,B00000111,B11111100,B00000000,
B11111000,B00000011,B11111000,B00000000
};


#define SWISHUV_H 13
#define SWISHUV_W 68
#define SWISHUV_X 58
#define SWISHUV_Y 2
static const unsigned char PROGMEM SWISHUV_BMP[] = {
B00000000,B00000000,B00000000,B00000000,B00000000,B00011110,B00011100,B11110000,B01110000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00011110,B00011100,B11110000,B11110000,
B00001111,B11100000,B00001111,B10000000,B11100000,B00011110,B00011100,B11110000,B11110000,
B00011111,B11111000,B00001111,B10000000,B11100000,B00011110,B00011100,B01111000,B11100000,
B00111111,B11111100,B00001111,B10000000,B11100000,B00011110,B00011100,B01111001,B11100000,
B00111111,B11111110,B00001111,B10000000,B11100000,B00011110,B00011100,B01111001,B11100000,
B01111111,B11111111,B00001111,B10011111,B11111110,B00011110,B00011100,B00111101,B11000000,
B01111110,B01111111,B10011111,B10011111,B11111110,B00011110,B00011100,B00111111,B11000000,
B01111100,B00111111,B11111111,B00000000,B11100000,B00011110,B00011100,B00011111,B11000000,
B11111100,B00011111,B11111111,B00000000,B11100000,B00011110,B00111100,B00011111,B10000000,
B11111000,B00001111,B11111110,B00000000,B11100000,B00011111,B00111100,B00011111,B10000000,
B11111000,B00000111,B11111100,B00000000,B11100000,B00001111,B11111000,B00001111,B10000000,
B11111000,B00000011,B11111000,B00000000,B00000000,B00000111,B11110000,B00001111,B00000000
};


#define ONUV_H  13
#define ONUV_W  70
#define ONUV_X  56
#define ONUV_Y  2
static const unsigned char PROGMEM ONUV_BMP[] = {
B00001111,B11000000,B00000000,B00000000,B00000000,B00000111,B10000111,B00111100,B00011100,
B00111111,B11110000,B00000000,B00000000,B00000000,B00000111,B10000111,B00111100,B00111100,
B01111100,B11110000,B00000000,B00000000,B00111000,B00000111,B10000111,B00111100,B00111100,
B01111000,B01111000,B11111111,B00000000,B00111000,B00000111,B10000111,B00011110,B00111000,
B01111000,B01111000,B11111111,B10000000,B00111000,B00000111,B10000111,B00011110,B01111000,
B11110000,B00111000,B11111111,B11000000,B00111000,B00000111,B10000111,B00011110,B01111000,
B11110000,B00111100,B11110011,B11000111,B11111111,B10000111,B10000111,B00001111,B01110000,
B11110000,B00111000,B11110011,B11000111,B11111111,B10000111,B10000111,B00001111,B11110000,
B01111000,B01111000,B11110011,B11000000,B00111000,B00000111,B10000111,B00000111,B11110000,
B01111000,B01111000,B11110011,B11000000,B00111000,B00000111,B10001111,B00000111,B11100000,
B01111100,B11110000,B11110011,B11000000,B00111000,B00000111,B11001111,B00000111,B11100000,
B00111111,B11110000,B11110011,B11000000,B00111000,B00000011,B11111110,B00000011,B11100000,
B00001111,B11000000,B11110011,B11000000,B00000000,B00000001,B11111100,B00000011,B11000000
};


#define ON_H  13
#define ON_W  26
#define ON_X  56
#define ON_Y  2
static const unsigned char PROGMEM ON_BMP[] = {
B00001111,B11000000,B00000000,B00000000,
B00111111,B11110000,B00000000,B00000000,
B01111100,B11110000,B00000000,B00000000,
B01111000,B01111000,B11111111,B00000000,
B01111000,B01111000,B11111111,B10000000,
B11110000,B00111000,B11111111,B11000000,
B11110000,B00111100,B11110011,B11000000,
B11110000,B00111000,B11110011,B11000000,
B01111000,B01111000,B11110011,B11000000,
B01111000,B01111000,B11110011,B11000000,
B01111100,B11110000,B11110011,B11000000,
B00111111,B11110000,B11110011,B11000000,
B00001111,B11000000,B11110011,B11000000
};

#endif