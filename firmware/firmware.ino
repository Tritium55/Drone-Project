#include "./return_home.h"
#include "./motor_control.h"
#include "./IBUS_Receiver.h"

//all user settings are included from this file
#include "./settings.h"


//uncomment next line for channel debugging
//#define SERIAL_WRITE_CHANNEL_OUT

//uncomment next line for pulse_map debugging
//#define SERIAL_WRITE_PULSE_MAP

//uncomment next line for temp_speed debugging
//#define SERIAL_WRITE_TEMP_SPEED

#define rh rclass
#define IBus IBus_Receiver

//create brushless motors
BrushlessMotor m1(BrushlessNr1);
BrushlessMotor m2(BrushlessNr2);
BrushlessMotor m3(BrushlessNr3);
BrushlessMotor m4(BrushlessNr4);


IBus receiver;                          //receiver init
Channels1to4_read Channels1to4;         //for return value of channel read

int pulse_map_CH1, pulse_map_CH2, pulse_map_CH3, pulse_map_CH4;


//maps all read values from function void readChannels
void mapReads(int lowChannel, int highChannel);


//returns 0, 1 or 2 depending on which value is currently mapped on pulse_map_CH6
int evaluateCh6(int val) {
  if (val == 1500) return 0;
  else if (val == 2000) return 1;
  else if (val == 1750) return 2;
}

//bool rh.returnHome(void);
//TODO: complex function which returns the drone home


//writes all motors
void write_motors(void) {
  m1.writeMotor();
  m2.writeMotor();
  m3.writeMotor();
  m4.writeMotor();
}

//resets speed of all motors
void reset_speed(void) {
  m1.setSpd(0);
  m2.setSpd(0);
  m3.setSpd(0);
  m4.setSpd(0);
}

//power off for drone
void poweroff() {
  reset_speed();
  write_motors();
  exit(0);
}

void setup() {
  //sensor_setup();                 //setups all sensors needed for return_home

  IBus_Receiver_Init();
  
  m1.BrushlessMotorInit();
  m2.BrushlessMotorInit();
  m3.BrushlessMotorInit();
  m4.BrushlessMotorInit();

  delay(5000);                      //delay for ESC init
}

int max_of_4(int a, int b, int c, int d) {
  int temp1 = max(a, b);
  int temp2 = max(c, d);
  return max(temp1, temp2);
}


int temp_spd1, temp_spd2, temp_spd3, temp_spd4;
void loop() {
  switch (evaluateCh6(receiver.readChannel6())) {
    case 0: break;
    case 1: poweroff();
            break;
    case 2: break;                            //change later for return home
  }

  temp_spd1 = temp_spd2 = temp_spd3 = temp_spd4 = 0;

  Channels1to4 = receiver.readChannels1to4();
  pulse_map_CH1 = map(Channels1to4.arr[0], RECEIVER_RANGE_MIN, RECEIVER_RANGE_MAX, CH_1_2_4_SENS_LOW, CH_1_2_4_SENS_HIGH);
  pulse_map_CH2 = map(Channels1to4.arr[1], RECEIVER_RANGE_MIN, RECEIVER_RANGE_MAX, CH_1_2_4_SENS_LOW, CH_1_2_4_SENS_HIGH);
  pulse_map_CH3 = map(Channels1to4.arr[2], RECEIVER_RANGE_MIN, RECEIVER_RANGE_MAX, CH_3_MIN_THROTTLE, CH_3_MAX_THROTTLE);
  pulse_map_CH4 = map(Channels1to4.arr[3], RECEIVER_RANGE_MIN, RECEIVER_RANGE_MAX, CH_1_2_4_SENS_LOW, CH_1_2_4_SENS_HIGH);

  #ifdef SERIAL_WRITE_PULSE_MAP
  Serial.print("pulse_map_CH1: ");
  Serial.println(pulse_map_CH1);
  Serial.print("pulse_map_CH2: ");
  Serial.println(pulse_map_CH2);
  Serial.print("pulse_map_CH3: ");
  Serial.println(pulse_map_CH3);
  Serial.print("pulse_map_CH4: ");
  Serial.println(pulse_map_CH4);

  delay(200);   //delay for printing
  #endif //SERIAL_WRITE_PULSE_MAP

  #ifdef SERIAL_WRITE_CHANNEL_OUT
  Serial.print("Channel 1: ");
  Serial.println(Channels1to4.arr[0]);
  Serial.print("Channel 2: ");
  Serial.println(Channels1to4.arr[1]);
  Serial.print("Channel 3: ");
  Serial.println(Channels1to4.arr[2]);
  Serial.print("Channel 4: ");
  Serial.println(Channels1to4.arr[3]);

  delay(200);   //delay for printing
  #endif //SERIAL_WRITE_CHANNEL_OUT

  //add spd of CH1 to motors      ROLL
  if (pulse_map_CH1 > 0) {
    temp_spd3 += pulse_map_CH1;
    temp_spd4 += pulse_map_CH1;
  }
  else {  //if(pulse_map_CH1<0)
    temp_spd1 += -pulse_map_CH1;
    temp_spd2 += -pulse_map_CH1;
  }


  //add spd of CH2 to motors      PITCH
  if (pulse_map_CH2 > 0) {
    temp_spd1 += pulse_map_CH2;
    temp_spd3 += pulse_map_CH2;
  }
  else {  //if(pulse_map_CH<0)
    temp_spd2 += -pulse_map_CH2;
    temp_spd4 += -pulse_map_CH2;
  }


  //add spd of CH4 to motors      YAW
  if (pulse_map_CH4 > 0) {
    temp_spd1 += pulse_map_CH4;
    temp_spd4 += pulse_map_CH4;
  }
  else {  //if(pulse_map_CH<=0)
    temp_spd2 += -pulse_map_CH4;
    temp_spd3 += -pulse_map_CH4;
  }


  //add spd of CH3 to motors      THROTTLE
  int temp_comparison = max_of_4(temp_spd1, temp_spd2, temp_spd3, temp_spd4);
  if (temp_comparison + pulse_map_CH3 >= CH_3_MAX_THROTTLE) {                   //bounds detection to not surpass motor spd limit
    int temp_val = (temp_comparison + pulse_map_CH3) - CH_3_MAX_THROTTLE;
    temp_spd1 += pulse_map_CH3 - temp_val;
    temp_spd2 += pulse_map_CH3 - temp_val;
    temp_spd3 += pulse_map_CH3 - temp_val;
    temp_spd4 += pulse_map_CH3 - temp_val;
  }
  else {
    temp_spd1 += pulse_map_CH3;
    temp_spd2 += pulse_map_CH3;
    temp_spd3 += pulse_map_CH3;
    temp_spd4 += pulse_map_CH3;
  }

  #ifdef SERIAL_WRITE_TEMP_SPEED
  Serial.print("temp_spd1: ");
  Serial.println(temp_spd1);
  Serial.print("temp_spd2: ");
  Serial.println(temp_spd2);
  Serial.print("temp_spd3: ");
  Serial.println(temp_spd3);
  Serial.print("temp_spd4: ");
  Serial.println(temp_spd4);

  delay(200);
  #endif //SERIAL_WRITE_TEMP_SPEED

  //write speeds to ESC's and set speeds to 0 afterwards
  m1.setSpd(temp_spd1);
  m2.setSpd(temp_spd2);
  m3.setSpd(temp_spd3);
  m4.setSpd(temp_spd4);
  write_motors();
  reset_speed();                    //sets speed of all motors to 0
}
