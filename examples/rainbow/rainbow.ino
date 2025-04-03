#include <Adafruit_GFX.h>         // Für einfache Grafikfunktionen
#include <Adafruit_NeoMatrix.h>   // Für die LED-Matrix
#include <Adafruit_NeoPixel.h>    // Wird von NeoMatrix genutzt

#define DATEN_PIN D4              // Pin, an dem die LEDs angeschlossen sind

// Wir erstellen eine neue Matrix mit 8x8 LEDs
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  8, 8, DATEN_PIN,
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800
);

int farbVerschiebung = 0;         // Damit sich die Farben bewegen

void setup() {
  matrix.begin();                 // Starte die Matrix
  matrix.setBrightness(100);     // Helligkeit der LEDs
}

void loop() {
  matrix.fillScreen(0);          // Löscht den Bildschirm

  // Jede LED bekommt eine Farbe, die sich mit x und farbVerschiebung verändert
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      uint16_t farbe = matrix.ColorHSV((x * 30 + farbVerschiebung) % 65536, 255, 255);
      matrix.drawPixel(x, y, farbe);
    }
  }

  matrix.show();                 // Zeige die neuen Farben an
  farbVerschiebung += 256;       // Ändere die Farben ein wenig
  delay(200);                     // Warte kurz, damit es nicht zu schnell wird
}