#include <Wire.h>
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h>
#include <Servo.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
Servo servo;

void setup() {
   servo.attach(2);
   servo.write(90);
   Serial.begin(9600);  
   if(!accel.begin())
  {
      Serial.println("No valid sensor found");
      while(1);
  }
}

void loop(void) {
   sensors_event_t event; 
   accel.getEvent(&event);
   int x = event.acceleration.x;
   int y = event.acceleration.y;
   int z = event.acceleration.z;
   if(x>2)
    servo.write(180);
   if(x<-2)
    servo.write(0);
   if(y>2)
    servo.write(180);
   if(y<-2)
    servo.write(0);
   delay(500);
}

