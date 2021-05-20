/***************************************************************
 * Pham Duy Anh - CKD - phamduyanh@gmail.com
 * Create: 08-09-2017
 * Update: 16-03-2021
 * Forum:  http://forum.cncprovn.com/forums/80-Arduino
 * 
 * This function will flash a LED with cycles
 *                                                         pinState          (stat flashing led, HIGHT or LOW);
 *             1       2       3       4 <---------------- numOfFlashes      (the number of times the leds flash in one cycle)
 *          ->| |<---------------------------------------- timeLED           (time led flash, ms)   >2ms
 *          ->| | | | |<---------------------------------- timePeriod        (time of a period, ms) >450ms
 *          ->| |                                     |<-- intervalLEDStatus (time of a cycle, ms)
 * Led on      _       _       _       _
 * Led off  __| |_____| |_____| |_____| |_____|_______|
 *          --------------------------------->|       |<-- end of a cycle, LED off a timePeriod
 *
 * Example:
 *  //LEDStatus(byte ledpin, byte numOfFlashes, byte maxFlashes, unsigned int intervalLEDStatus, byte pinState)
 *  #include "src/LEDStatus.h"
 *  or
 *  #include <LEDStatus.h>
 *
 *  LEDStatus ledstatus(LED_PIN, 1, 5, 2500, 1);
 *  void loop()
 *  {
 *    ledstatus.run();
 *  }
 * 
 * Attention:
 *   The cycle will not be accurate if the loop() time is too large
 **************************************************************/

#ifndef LEDStatus_h
#define LEDStatus_h

#include <Arduino.h>

#define _timeLED    3
#define _timePeriod 500

class LEDStatus {
  public:
    LEDStatus(byte ledpin, byte numOfFlashes, byte maxFlashes, unsigned int intervalLEDStatus, byte pinState);
    void set(unsigned int num);
    void run();
  private:
    unsigned long _timeLEDStatus;
    unsigned int  _intervalLEDStatus;
    byte _ledpin;
    byte _pinState;
    byte _maxFlashes;
    byte _numOfFlashes;
    byte _numOfFlashed;
    bool _ledStatus;
};
#endif