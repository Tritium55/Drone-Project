#include "return_home.h"
#include "motor_control.h"
#include "IBUS_Receiver.h"

#define return_home Rh
#define BrushlessMotor Mc
#define IBus_Receiver_Drone IBus



#define BrushlessNr1 8
#define BrushlessNr2 9
#define BrushlessNr3 10
#define BrushlessNr4 11


/*
//Mc m1, m2, m3, m4;    //create brushless motors
BrushlessMotor m1(BrushlessNr1);
BrushlessMotor m2(BrushlessNr2);
BrushlessMotor m3(BrushlessNr3);
BrushlessMotor m4(BrushlessNr4);
delay(5000);          //delay to let the ESC's initialize them
*/

IBus_Receiver_Drone receiver;



int pulse_map_CH1, pulse_map_CH2, pulse_map_CH3, pulse_map_CH4;
int pulse_map_CH6;


//maps all read values from function void readChannels
void mapReads(int lowChannel, int highChannel);


//returns 0, 1 or 2 depending on which value is currently mapped on pulse_map_CH6
int evaluateCh6(int val){
  if(val==1500) return 0;
  else if(val==2000) return 1;
  else if(val==1750) return 2;
}

//bool rh.returnHome(void);
//complex function which returns the drone home



void setup() {
  //sensor_setup();                 //setups all sensors needed for return_home

  delay(5000);                      //delay for ESC init
}

int temp;
void loop() {
  evaluateCh6(receiver.readChannel6())==1 && exit(0);

  Channels1to4.arr = receiver.readChannels1to4();
  pulse_map_CH1 = map(Channels1to4.arr[0], 1000, 2000, 0, 1000);
  pulse_map_CH2 = map(Channels1to4.arr[1], 1000, 2000, -50, 50);
  pulse_map_CH3 = map(Channels1to4.arr[2], 1000, 2000, -50, 50);
  pulse_map_CH4 = map(Channels1to4.arr[3], 1000, 2000, -50, 50);

  

  reset_speed();                    //sets speed of all motors to 0
}
