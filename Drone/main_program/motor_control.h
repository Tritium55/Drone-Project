#ifndef motor_control_h
#define motor_control_h

#include <Servo.h>

class BrushlessMotor{
    private:
        Servo motorType;
        int speed;                      //range of 0 - 1000
        void writeMotor(void);          //write private var speed to motor
        int pin;
    public:
        BrushlessMotor(int pin);
        void setSpeed(int speed);       //public method to set speed of motor
}m1(BrushlessNr1), m2(BrushlessNr2), m3(BrushlessNr3), m4(BrushlessNr4);

void reset_speed(void);

extern BrushlessMotor motor_control;

#endif