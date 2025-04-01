#include <FastLED.h>
#include <Vector.h>
using namespace std;

#define LED_PIN     D4
#define PIXEL_ZEILEN  8
#define PIXEL_SPALTEN  8
#define NUM_LEDS    (PIXEL_ZEILEN * PIXEL_SPALTEN)
#define HELLIGKEIT  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(0);
  FastLED.show();
}

void loop() {
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i = 0; i < HELLIGKEIT; i++){
    FastLED.setBrightness(i);
    FastLED.show();
    delay(50);
  }
  for(int i = HELLIGKEIT; i >= 0; i--){
    FastLED.setBrightness(i);
    FastLED.show();
    delay(50);
  }
}