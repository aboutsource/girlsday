#include <FastLED.h>

#define LED_PIN     D4

#define PIXEL_ROWS  8

#define PIXEL_COLS  8

#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)

#define BRIGHTNESS  30

#define LED_TYPE    WS2812B

#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
int Stiel []= {36, 43, 44, 51, 52, 59, 60}; 
int Blume []= {10, 13, 18, 19, 20, 21, 36, 27, 28, 35, 26, 28, 29}; 

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
  for(int i = 0; i < sizeof(Stiel)/sizeof(Stiel[0]); i++){
    leds[Stiel[i]] = CRGB::Green;
  }
  for(int i = 0; i < sizeof(Blume)/sizeof(Blume[0]); i++){
    leds[Blume[i]] = CRGB::Red;
  }
  FastLED.show();
}

void loop() {
}
    
  
