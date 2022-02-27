#include "Arduino.h"
#include "motor_control.h"


BrushlessMotor::BrushlessMotor(int x) : pin(x) {
    motorType.attach(pin);
    motorType.writeMicroseconds(1000);
}

void BrushlessMotor::setSpd(int _spd){
    spd = _spd;
}

void BrushlessMotor::writeMotor(void){
    motorType.writeMicroseconds(map(spd, 0, 1000, 1000, 2000));             //write speed to servo (motorType of type Servo)
}
