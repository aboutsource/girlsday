# Arduino

## Programm installieren

Arduino IDE über Store oder Console installieren

## Mikrocontroller hinzufügen

In der Arduino IDE unter `Datei` -> `Einstellungen` bei "Zusätzliche Boardverwalter-URLs" hinzufügen:

    https://arduino.esp8266.com/stable/package_esp8266com_index.json

![screenshot_einstellungen_boardverwaltung](images/screenshot_einstellungen_board.png "URL an der rot umrandeten Stelle einfügen")

Unter `Werkzeuge` -> `Board` -> `Board-Verwaltung`

    esp8266

suchen und installieren

![screenshot_board_verwaltung_esp8266](images/screenshot_esp8266.png "in der Board-Verwaltung esp8266 installieren")

Unter `Werkzeuge` -> `Board` -> `esp8266`

    LOLIN(WEMOS) D1 mini Lite

auswählen

Gegebenenfalls unter `Werkzeuge` -> `Port` den richtigen auswählen

## Bibliotheken hinzufügen

In der Arduino IDE unter `Werkzeuge` -> `Bibliotheken verwalten`

    FastLED

und

    Vector

jeweils suchen und installieren

![screenshot_bibliothek_fast_led](images/screenshot_fast_led.png "Im Bibliotheksverwalter FastLed installieren")
![screenshot_bibliothek_vector](images/screenshot_vector.png "Im Bibliotheksverwalter Vector installieren")

# Beispiele

## Beispiele herunterladen

Oben auf den grünen Button `Code` und dann auf `Download ZIP` klicken

![screenshot_beispiele_herunterladen](images/screenshot_beispiele_herunterladen.png "Beispiele an der rot umrandeten Stelle herunterladen")

Den ZIP-Ordner könnt ihr auf eurem Computer vom Ordner `Downloads` in den Ordner `Arduino` verschieben und dort entpacken (rechte Maustaste und `enpacken` auswählen)




