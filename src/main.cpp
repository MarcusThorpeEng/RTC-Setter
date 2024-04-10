#include <Arduino.h>
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  
  // Check if the RTC is connected properly
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Check if the RTC lost power and if so, set the time - this will run on first tiem
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // Set the RTC to a specific date and time
    // rtc.adjust(DateTime(year, month, day, hour, minute, second));
    rtc.adjust(DateTime(2024, 1, 1, 12, 0, 0)); // January 1, 2024, 12:00:00
  }
}

void loop() {
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  
  delay(1000);
}