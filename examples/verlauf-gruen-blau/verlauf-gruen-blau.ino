#include <FastLED.h>

#define LED_PIN     D4         // Daten-Pin
#define ANZAHL_LEDS 64         // 8x8 Matrix
#define HELLIGKEIT  100
#define LED_TYP     WS2812B
#define FARBREIHENFOLGE GRB

CRGB leuchtdioden[ANZAHL_LEDS];

void setup() {
  // LED-Array initialisieren
  FastLED.addLeds<LED_TYP, LED_PIN, FARBREIHENFOLGE>(leuchtdioden, ANZAHL_LEDS);
  FastLED.setBrightness(HELLIGKEIT);
}

void loop() {
  // Verschiebung für die Animation
  static uint8_t verschiebung = 0;

  // Definition der Farbgrenzen (Hue-Werte: Grün und Blau)
  uint8_t gruenHue = 96;  // Farbton für Grün
  uint8_t blauHue  = 160; // Farbton für Blau

  // Gehe jede Zeile und Spalte der 8x8 Matrix durch
  for (int zeile = 0; zeile < 8; zeile++) {
    for (int spalte = 0; spalte < 8; spalte++) {
      int index = zeile * 8 + spalte;  // Berechne den Index im LED-Array

      // Berechne den Anteil (0.0 bis 1.0) für den Farbverlauf
      float anteil = ((float)((spalte + verschiebung) % 8)) / 7.0;
      // Interpoliere den Farbton zwischen grün und blau
      uint8_t farbton = gruenHue + anteil * (blauHue - gruenHue);

      // Setze die LED-Farbe
      leuchtdioden[index] = CHSV(farbton, 255, 255);
    }
  }

  FastLED.show(); // Aktualisiere die LEDs
  verschiebung++; // Erhöhe die Verschiebung für die Animation
  delay(50);      // Kurze Pause
}