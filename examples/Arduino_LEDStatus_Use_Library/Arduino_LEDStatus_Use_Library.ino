#include "src/LEDStatus.h" // or #include <LEDStatus.h>
#define LED_PIN 13 // for UNO

LEDStatus ledstatus(LED_PIN, 1, 5, 2500, 1);

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(200);
}

void loop()
{
  if(Serial.available() > 0)
  {
    ledstatus.setNum(Serial.parseInt());
  }

  ledstatus.run();
}
