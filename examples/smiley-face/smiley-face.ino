#include <FastLED.h>

#define LED_PIN     D4

#define PIXEL_ROWS  8

#define PIXEL_COLS  8

#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)

#define BRIGHTNESS  30

#define LED_TYPE    WS2812B

#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
int kopf[] = {3, 4, 5, 10, 14, 17, 14, 23, 25, 31, 33, 39, 42, 46, 51, 52, 53};
int augen[] = {19, 21};
int mund1[] = {35, 37, 44};
int mund2[] = {36, 43, 45};

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
  for(int i = 0; i < sizeof(kopf)/sizeof(kopf[0]); i++){
    leds[kopf[i]] = CRGB::Orange;
  }
  for(int i = 0; i < sizeof(augen)/sizeof(augen[0]); i++){
    leds[augen[i]] = CRGB::DarkBlue;
  }
  FastLED.show();
}

void loop() {
  for(int i = 0; i < sizeof(mund1)/sizeof(mund1[0]); i++){
    leds[mund2[i]] = CRGB::Black;
    leds[mund1[i]] = CRGB::Red;
  }
  FastLED.show();
  delay(500);
  for(int i = 0; i < sizeof(mund2)/sizeof(mund2[0]); i++){
    leds[mund1[i]] = CRGB::Black;
    leds[mund2[i]] = CRGB::Red;
  }
  FastLED.show();
  delay(500);
}