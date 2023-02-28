#include <Arduino.h>
#include "motor_control.h"

#include "./settings.h"

BrushlessMotor::BrushlessMotor(int x) : pin(x) {
}

void BrushlessMotor::BrushlessMotorInit(){
  motorType.attach(pin, ESC_RANGE_MIN, ESC_RANGE_MAX);
  motorType.writeMicroseconds(ESC_RANGE_MIN);
}

void BrushlessMotor::setSpd(int _spd){
    spd = _spd;
}

void BrushlessMotor::writeMotor(void){
    int locspd = map(spd, CH_3_MIN_THROTTLE, CH_3_MAX_THROTTLE, ESC_RANGE_MIN, ESC_RANGE_MAX);
    motorType.writeMicroseconds(locspd);             //write speed to servo (motorType of type Servo)
}
