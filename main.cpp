#include <Arduino.h>

/*
 ____       _                    _             
|  _ \  ___| |_ ___  _ __   __ _| |_ ___  _ __ 
| | | |/ _ \ __/ _ \| '_ \ / _` | __/ _ \| '__|
| |_| |  __/ || (_) | | | | (_| | || (_) | |   
|____/ \___|\__\___/|_| |_|\__,_|\__\___/|_|   

This is the check version of the remote detonator,
 it checks if the component gives a higher voltage than 2 on pin 15 and if it doesnt, it will wait 2,5 seconds then go off,
as this is the perfect time to drop something from 30 meters. This could be used in a war such as the one in Ukraine,with a drone but shouldnt be used by an untrained,
or illegaly operating person.

THIS PROJECT IS STRICTLY FOR EDUCATIONAL AND ENTER- or rather INFOTAINMENT PURPOSES.
MISSUSE IS NOT TO BE TOLERATED!

*/




double value;
double voltage;


void setup() {
  Serial.begin(9600);
  pinMode(23, OUTPUT);
  pinMode(15, INPUT);
}

void loop() {
  value = analogRead(15);
  voltage = value * (3.3 / 4095);
  Serial.println(voltage);

  if (voltage < 2) {
    delay(2500);
    while (true) {
      digitalWrite(23, HIGH);
      delay(10);
      digitalWrite(23, LOW);
      delay(10);
    }
  } else {
    delay(300);
  }
}