#include "Arduino.h"
#include "motor_control.h"


BrushlessMotor::BrushlessMotor(int pin){
    self.pin = pin;
    self.motorType.attach(self.pin);
    self.motorType.writeMicroseconds(1000);
}

void BrushlessMotor::setSpeed(int speed){
    self.speed = speed;
}

void BrushlessMotor::writeMotor(void){
    self.motorType.writeMicroseconds(map(self.speed, 0, 1000, 1000, 2000));
}


//resets speed of all motors
void reset_speed(void){
    m1.setSpeed(0);
    m2.setSpeed(0);
    m3.setSpeed(0);
    m4.setSpeed(0);
}
