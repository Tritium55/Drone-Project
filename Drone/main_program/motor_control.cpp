#include "Arduino.h"
#include "motor_control.h"


BrushlessMotor::BrushlessMotor(int pin){
    self.pin = pin;
    self.motorType.attach(self.pin);
    self.motorType.writeMicroseconds(1000);
}

void BrushlessMotor::setSpeed(int speed){
    self.speed = speed;
    self.writeMotor();
}

void BrushlessMotor::writeMotor(void){
    self.motorType.writeMicroseconds(map(speed, 0, 1000, 1000, 2000));
}
