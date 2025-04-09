#include <FastLED.h>

#define LED_PIN     D4

#define PIXEL_ROWS  8

#define PIXEL_COLS  8

#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)

#define BRIGHTNESS  30

#define LED_TYPE    WS2812B

#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
int kopf[] = {27, 29};
int schnabel[] = {30};
int federn[] = {18, 19, 20, 21, 26, 28, 33, 34, 35, 36, 37, 41, 42, 43, 44, 45, 50, 51, 52, 53};

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  fill_solid(leds, NUM_LEDS, CRGB::Aqua);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();

}

void loop() {
  for(int i = 0; i < sizeof(kopf)/sizeof(kopf[0]); i++){
    leds[kopf[i]] = CRGB::Black;
  }
  for(int i = 0; i < sizeof(schnabel)/sizeof(schnabel[0]); i++){
    leds[schnabel[i]] = CRGB::Orange;
  }
  for(int i = 0; i < sizeof(federn)/sizeof(federn[0]); i++){
    leds[federn[i]] = CRGB::Yellow;
  }
  
  FastLED.show();
}
