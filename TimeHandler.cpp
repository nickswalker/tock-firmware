#include "TimeHandler.h"
#include <TimeAlarms.h>
#include <DS1307RTC.h>
#include <Time.h>

void TimeHandler::init(){
  //Read from the RTC and set the our soft clock based off of it, if not set a default
    tmElements_t tm;
  //The RTC library is fully static. Might want to write a new version? Investigate why.
  if (RTC.read(tm)) {
    //These members are capitalized too... Another reason to consider revising.
    setTime(tm.Hour, tm.Minute, tm.Second, tm.Day, tm.Month, tm.Year);
    Serial.println("Constructed");
  }
  else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped");
    } else {
      Serial.println("DS1307 read error");
    }
  }
  setSyncProvider(RTC.get);
}
TimeHandler::~TimeHandler(){
   Serial.println("Deconstructed");
}
unsigned int TimeHandler::getTimeForDisplay(){
  //four digit number.
  return (hour() *100) + minute();
}
byte TimeHandler::getSecond(){
  //four digit number.
  return second();
}

void setAlarm(){}
void TimeHandler::alarm(){
  
}

