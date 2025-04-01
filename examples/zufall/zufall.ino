#include <FastLED.h>
#include <Vector.h>
using namespace std;

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

vector<int> pixel;
bool enthalten = false;
int zufall_pixel;
int zufall_farbe;

void loop() {
  zufall_pixel = (rand()%64);
  zufall_farbe = (rand()%256);
  for(int i = 0; i < pixel.size(); i++){
    if(zufall_pixel == pixel[i]){
      enthalten = true;
    }
  }
  if(enthalten == false){
    pixel.push_back(zufall_pixel);
    leds[zufall_pixel].setHue(zufall_farbe);
    FastLED.show();
    delay(100);
  } else {
    enthalten = false;
  }
  if(pixel.size() > 36){
    leds[pixel.front()] = CRGB::Black;
    pixel.erase(pixel.begin());
    FastLED.show();
  }
}