#include <FastLED.h>

#define LED_PIN     D4

#define PIXEL_ROWS  8

#define PIXEL_COLS  8

#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)

#define BRIGHTNESS  30

#define LED_TYPE    WS2812B

#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];


int Pinguin[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 23, 24, 31, 32, 33, 38, 39, 40, 47, 48, 49, 50, 51, 52, 53, 54, 55, };
int Schnabel[] = { 19, 20, };
int Fuesse[] = { 58, 61, };
int Augen[] = { 10, 13, };
int Herz[] = { 9, 10, 13, 14, 16, 19, 20, 23, 24, 31, 33, 38, 42, 45, 51, 52};

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

void loop() {
  for(int i = 0; i < sizeof(Pinguin)/sizeof(Pinguin[0]); i++) {
    leds[Pinguin[i]] = CRGB::Blue;
  }
  for(int i = 0; i < sizeof(Fuesse)/sizeof(Fuesse[0]); i++) {
    leds[Fuesse[i]] = CRGB::Yellow;
  }
  for(int i = 0; i < sizeof(Schnabel)/sizeof(Schnabel[0]); i++) {
    leds[Schnabel[i]] = CRGB::Yellow;
  }
  for(int i = 0; i < sizeof(Augen)/sizeof(Augen[0]); i++) {
    leds[Augen[i]] = CRGB::Pink;
  }
  FastLED.show();
  delay(3000);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i = 0; i < sizeof(Herz)/sizeof(Herz[0]); i++) {
    leds[Herz[i]] = CRGB::Red;
  }
  
  FastLED.show();
  delay(3000);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
}
