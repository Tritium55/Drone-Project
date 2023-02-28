#ifndef motor_control_h
#define motor_control_h

#include <Servo.h>

class BrushlessMotor{
    private:
        Servo motorType;
        int spd;                        //range of 0 - 1000
        int pin;
    public:
        BrushlessMotor(int x);
        void BrushlessMotorInit(void);  //initializes the Brushless Motor (must be used in void setup() function)
        void writeMotor(void);          //write private var speed to motor
        void setSpd(int _spd);          //public method to set speed of motor
};

#endif  //motor_control_h
