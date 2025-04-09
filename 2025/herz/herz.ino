
#include <FastLED.h>

#define LED_PIN     D4

#define PIXEL_ROWS  8

#define PIXEL_COLS  8

#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)

#define BRIGHTNESS  30

#define LED_TYPE    WS2812B

#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

int rot[]  = {19,21,27,28,29,36,0,1,2,3,4,5,6,7,8,9,15,16,24,32,40,48,56,57,58,59,60,61,2,63,42,42,43,50,51,53,54,55,47,46,45,38,39,31,23,15};

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

void loop() {
  for(int i = 0; i< sizeof(rot)/sizeof(rot[0]); i++){
    leds[rot[i]] = CRGB::Red;
  }
  FastLED.show(); 
}
