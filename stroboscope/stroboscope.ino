#include <FastLED.h>

#define LED_PIN     D4
#define PIXEL_ROWS  8
#define PIXEL_COLS  8
#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)
#define BRIGHTNESS  255    // 100% brightness
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

void loop() {
  // Strobe effect: Turn all LEDs white
  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(50); // short on-time
  // Turn all LEDs off
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(50); // short off-time
}