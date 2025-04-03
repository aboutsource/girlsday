#include <FastLED.h>

#define LED_PIN     D4        // Pin für die Lichter
#define ANZAHL_LEDS 64        // 8x8 = 64 Lichter
#define HELLE       100       // Helligkeit

CRGB lichter[ANZAHL_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(lichter, ANZAHL_LEDS);
  FastLED.setBrightness(HELLE); // Helligkeit einstellen
}

void loop() {
  static uint8_t farbVerschiebung = 0; // Farbe wandert mit der Zeit

  // Wir gehen durch jede Zeile (y) und Spalte (x)
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int nummer = ledNummer(x, y); // Die richtige LED-Nummer finden
      lichter[nummer] = CHSV((x * 10 + farbVerschiebung) % 255, 255, 255); // Bunte Farben
    }
  }

  FastLED.show();    // Lichter anzeigen
  farbVerschiebung++; // Farbe ändern
  delay(50);         // Kleine Pause
}

// Die Lichter sind von links nach rechts sortiert
int ledNummer(int x, int y) {
  return y * 8 + x;
}