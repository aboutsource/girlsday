#include <FastLED.h>

#define LED_PIN     D4

#define PIXEL_ROWS  8

#define PIXEL_COLS  8

#define NUM_LEDS    (PIXEL_ROWS * PIXEL_COLS)

#define BRIGHTNESS  30

#define LED_TYPE    WS2812B

#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
int herz[] = {19, 10, 9, 16, 24, 33, 42, 51, 52, 45, 38, 31, 23, 14, 13, 20, };

int rot[] = {1, 9, 17, 25, 33, 41, 49, 57, };
int orange[] = { 2, 10, 18, 26, 34, 42, 50, 58, };
int gelb[] = {3, 11, 19, 27, 35, 43, 51, 59, };
int gruen[] = {4, 12, 20, 28, 36, 44, 52, 60, };
int blau[] = {5, 13, 21, 29, 37, 45, 53, 61, };
int lila[] = {6, 14, 22, 30, 38, 46, 54, 62, };
void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

void loop() {

  for(int i = 0; i < sizeof(herz)/sizeof(herz[0]); i++){
    leds[herz[i]] = CRGB::Red;
  }
  FastLED.show();
  delay(500);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
    
  for(int i = 0; i < sizeof(rot)/sizeof(rot[0]); i++){
    leds[rot[i]] = CRGB::Red;
  }
    for(int i = 0; i < sizeof(orange)/sizeof(orange[0]); i++){
    leds[orange[i]] = CRGB::Orange;
  }
    for(int i = 0; i < sizeof(gelb)/sizeof(gelb[0]); i++){
    leds[gelb[i]] = CRGB::Yellow;
  }
    for(int i = 0; i < sizeof(gruen)/sizeof(gruen[0]); i++){
    leds[gruen[i]] = CRGB::Green;
  }
    for(int i = 0; i < sizeof(blau)/sizeof(blau[0]); i++){
    leds[blau[i]] = CRGB::Blue;
  }
    for(int i = 0; i < sizeof(lila)/sizeof(lila[0]); i++){
    leds[lila[i]] = CRGB::Purple;
  }
  FastLED.show();
  delay(500);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
}
