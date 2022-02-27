#include <Servo.h>

Servo brushless3;

#define brushlessNr3 8

int var_speed = 50;

int temp;

void setup() {
  brushless3.attach(brushlessNr3);
  //Serial.begin(9600);
  brushless3.writeMicroseconds(1000);
  delay(5000);
}

void loop() {
  temp = map(var_speed, 0, 1023, 1000, 2000);
  brushless3.writeMicroseconds(temp);
  //Serial.println(temp);
}
