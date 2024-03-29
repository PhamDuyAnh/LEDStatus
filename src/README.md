# LEDStatus
* Pham Duy Anh - CKD - 0908984010 - phamduyanh@gmail.com
* Create: 08-09-2017
* Update: 05-11-2023
* Githup: https://github.com/PhamDuyAnh/LEDStatus
  
### LEDStatus
This function will flash a LED with cycles
```
                                                         pinState          (stat flashing led, HIGHT or LOW);
             1       2       3       4 <---------------- numOfFlashes      (the number of times the leds flash in one cycle)
          ->| |<---------------------------------------- timeLED           (time led flash, ms)   >2ms
          ->| | | | |<---------------------------------- timePeriod        (time of a period, ms) >450ms
          ->| |                                     |<-- intervalLEDStatus (time of a cycle, ms)
 Led on      _       _       _       _
 Led off  __| |_____| |_____| |_____| |_____|_______|
          --------------------------------->|       |<-- end of a cycle, LED off minimum a timePeriod or longer
``` 
### Example:
```
//LEDStatus(byte ledpin, byte numOfFlashes, byte maxFlashes, unsigned int intervalLEDStatus, byte pinState)
#include "src/LEDStatus.h"
or
#include <LEDStatus.h>

LEDStatus ledstatus(LED_PIN, 1, 5, 2500, 1);
void loop()
{
  ledstatus.run();
}

Set numOfFlashes or intervalLEDStatus
  ledstatus.setFlashes(X); X < maxFlashes   --> set numOfFlashes
  ledstatus.setInterval(X)                  --> set intervalLEDStatus
LED flasher
  ledstatus.ledFlasher()                    --> led flashed one time
  ledstatus.ledFlasher(X)                   --> led flashed X times
```
> [!WARNING]
> The cycle will not be accurate if the loop() time is too large
