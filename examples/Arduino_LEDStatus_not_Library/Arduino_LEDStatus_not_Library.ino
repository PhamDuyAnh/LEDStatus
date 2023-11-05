#include "src/LEDStatus.h"
#define LED_PIN 13

LEDStatus ledstatus(LED_PIN, 1, 5, 2500, 1);

void setup()
{
  LEDFlashes(LED_PIN, 5, 1)
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.setTimeout(200);
}

int i = 0;
void loop()
{
  if(Serial.available() > 0)
  {
    i = Serial.parseInt();
  }

  LEDStatusFlashes(LED_PIN, i, 2500, 1);
}


#define timeLED 10
#define timeCycle 200
void LEDStatusFlashes(byte pin, byte timeBlink, unsigned int intervalLEDStatus, byte state) {
  static unsigned long timeLEDStatus;
  static byte timeBlinked;
  static bool ledStatus;

  pinMode(pin, OUTPUT);

  if (millis() - timeLEDStatus > intervalLEDStatus) {
    ledStatus = true;
    timeBlinked = 1;
    timeLEDStatus = millis();
  }

  long checkTime = millis() - (timeLEDStatus + (unsigned long)timeBlinked * timeCycle);

  if (ledStatus && (checkTime > 0)) {
    timeBlinked++;
    if (timeBlinked > timeBlink) {
      timeBlinked = 0;
      ledStatus = false;
    }
    digitalWrite(pin, state);
    delay(timeLED);
    digitalWrite(pin, !state);
  } else {
    digitalWrite(pin, !state);
  }
}
void LEDFlashes(byte pin, byte n, byte state) {
  pinMode(pin, OUTPUT);
  for (byte i = 0; i < N; i++) {
    digitalWrite(PIN_LED, state);
    delay(timeLED);
    digitalWrite(PIN_LED, !state);
    delay(timeLED);
  }
}