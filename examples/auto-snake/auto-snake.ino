#include <Adafruit_NeoPixel.h>

#define PIN D4          // Data pin for the LED panel
#define NUMPIXELS 64   // 8x8 panel

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Function to map (x,y) coordinates to the pixel index
int getPixelIndex(int x, int y) {
  // Assumes a row-major order starting at the top left.
  return y * 8 + x;
}

void setup() {
  pixels.begin();
  pixels.setBrightness(50); // Adjust brightness if needed
}

void loop() {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int pixelIndex = getPixelIndex(x, y);
      // Top left quadrant: Blue
      if (x < 4 && y < 4) {
        pixels.setPixelColor(pixelIndex, pixels.Color(0, 0, 255));
      }
      // Top right quadrant: Green
      else if (x >= 4 && y < 4) {
        pixels.setPixelColor(pixelIndex, pixels.Color(0, 255, 0));
      }
      // Bottom left quadrant: Red
      else if (x < 4 && y >= 4) {
        pixels.setPixelColor(pixelIndex, pixels.Color(255, 0, 0));
      }
      // Bottom right quadrant: Yellow (Red + Green)
      else {
        pixels.setPixelColor(pixelIndex, pixels.Color(255, 255, 0));
      }
    }
  }
  pixels.show();
  delay(1000);  // Update every second
}