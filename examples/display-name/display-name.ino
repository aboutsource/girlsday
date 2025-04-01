#include <Adafruit_NeoMatrix.h>
#include <Adafruit_GFX.h>

#define PIN D4

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  8, 8, PIN,
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800
);

const char* text = "about:source";  
int textWidth = 6 * strlen(text);
int x = matrix.width();  // Starte komplett rechts außerhalb des Panels

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(matrix.Color(0, 0, 255));  // Blauer Text
}

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(text);
  matrix.show();

  x--;  // Bewege den Text spaltenweise nach links

  // Sobald der gesamte Text links außerhalb ist, reset x
  if (x < -textWidth) {
    x = matrix.width();
  }
  
  delay(100);
}