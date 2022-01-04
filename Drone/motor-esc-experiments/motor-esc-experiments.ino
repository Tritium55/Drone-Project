#include <Servo.h>

Servo brushless3;

#define brushlessNr3 8

int var_speed = 400;

int temp;

void setup() {
  brushless3.attach(8);
  brushless3.writeMicroseconds(1000);
  Serial.begin(9600);
}

void loop() {
  temp = map(var_speed, 0, 1023, 1000, 2000);
  Serial.println(temp);
  brushless3.writeMicroseconds(temp);
}
