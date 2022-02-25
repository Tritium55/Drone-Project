#ifndef motor_control_h
#define motor_control_h

#include <Servo.h>

class BrushlessMotor{
    private:
        Servo motorType;
        int spd;                        //range of 0 - 1000
        int pin;
    public:
        BrushlessMotor(int pin);
        void writeMotor(void);          //write private var speed to motor
        void setSpd(int spd);         //public method to set speed of motor
};

#endif
