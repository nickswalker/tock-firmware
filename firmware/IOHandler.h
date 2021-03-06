#ifndef IOHandler_H
#define IOHandler_H

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class IOHandler {
public:
  void init();
        
  void displayTime(byte hour, byte minute, byte second);
  void setBrightness(byte value);
        
  boolean checkIfSnoozeButtonWasPressed();
  void setAlarmState(boolean state);
  boolean getAlarmState();

        
private:
  boolean alarmIsOn;
        
};
 
#endif
