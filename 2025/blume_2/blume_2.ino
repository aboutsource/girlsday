#include <FastLED.h>

#define LED_PIN     D4

#define PIXEL_ROWS  8

#define PIXEL_COLS  8

#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)

#define BRIGHTNESS  30

#define LED_TYPE    WS2812B

#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
int schwarz []= {29,35,45,52,};
int blätter []= {4,11,12,13,18,19,20,21,22,28,};
int rot []= {26,27,30,34,36,37,38,42,43,44,46,51,53,};

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}


void loop() {
  for(int i = 0; i < sizeof(blätter)/sizeof(blätter[0]); i++){
    leds[blätter[i]] = CRGB::Green;
  }
  for(int i = 0; i < sizeof(schwarz)/sizeof(schwarz[0]); i++){
    leds[schwarz[i]] = CRGB::Black;
  }
  for(int i = 0; i < sizeof(rot)/sizeof(rot[0]); i++){
    leds[rot[i]] = CRGB::Red;
  }
  FastLED.show();
}
