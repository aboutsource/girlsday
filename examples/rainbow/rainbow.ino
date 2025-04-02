#include <FastLED.h>

#define LED_PIN     D4         // Data pin
#define NUM_LEDS    64        // 8x8 Panel
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    static uint8_t offset = 0;
  
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        int index = getLedIndex(x, y);
        leds[index] = CHSV((x * 10 + offset) % 255, 255, 255);
      }
    }
  
    FastLED.show();
    offset++;
    delay(50);
  }
  
bool serpentine = false; // false = progressive layout

int getLedIndex(int x, int y) {
  if (serpentine && (y % 2 == 1)) {
    return y * 8 + (7 - x);
  } else {
    return y * 8 + x;
  }
}
