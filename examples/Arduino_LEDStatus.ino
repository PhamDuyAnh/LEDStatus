//#include "src/LEDStatus.h"
#include "LEDStatus.h"
#define LED_PIN 13

LEDStatus ledstatus(LED_PIN, 1, 5, 2500, 1);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if(Serial.available() > 0)
  {
    ledstatus.set(Serial.parseInt());
  }

  ledstatus.run();
}
