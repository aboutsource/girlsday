#include <FastLED.h>

#define LED_PIN     D4
#define PIXEL_ZEILEN  8
#define PIXEL_SPALTEN  8
#define NUM_LEDS    (PIXEL_ZEILEN * PIXEL_SPALTEN)
#define HELLIGKEIT  10
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(HELLIGKEIT);
  FastLED.show();
}

int farbe;

void loop() {
  farbe = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 64; j++){
      farbe++;
      leds[j].setHue(farbe);
      FastLED.show();
      delay(50);
    }
  }
}