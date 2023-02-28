#ifndef settings_h
#define settings_h

//! USER SETTINGS BEGIN HERE

//define Serial Input for IBUS Receiver Output
#define SERIAL_INPUT Serial1

//define pins of all 4 brushless motors
#define BrushlessNr1 16
#define BrushlessNr2 8
#define BrushlessNr3 10
#define BrushlessNr4 9

//define pins of GY-521 Gyroscope
#define GY521_SCL A3
#define GY521_SDA A2

//define sensitivity of all channels exept THROTTLE
#define CH_1_2_4_SENS_LOW -200
#define CH_1_2_4_SENS_HIGH 199

//define range of THROTTLE
#define CH_3_MIN_THROTTLE 0
#define CH_3_MAX_THROTTLE 1000

//ESC PWM RANGE
#define ESC_RANGE_MIN 1000
#define ESC_RANGE_MAX 2000

//RECEIVER PWM RANGE
#define RECEIVER_RANGE_MIN 1000
#define RECEIVER_RANGE_MAX 2000


//! USER SETTINGS END HERE


#endif  //settings_h
