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


//Mc m1, m2, m3, m4;    //create brushless motors
BrushlessMotor m1(BrushlessNr1);
BrushlessMotor m2(BrushlessNr2);
BrushlessMotor m3(BrushlessNr3);
BrushlessMotor m4(BrushlessNr4);
delay(5000);          //delay to let the ESC's initialize them

int pulse_read_CH1, pulse_read_CH2, pulse_read_CH3, pulse_read_CH4;
int pulse_read_CH6;
int pulse_map_CH1, pulse_map_CH2, pulse_map_CH3, pulse_map_CH4;
int pulse_map_CH6;


//maps all read values from function void readChannels
void mapReads(int lowChannel, int highChannel);


//returns 0, 1 or 2 depending on which value is currently mapped on pulse_map_CH6
int evaluateCh6(int val){
  if(val==1500) return 0;
  else if(val==2000) return 2;
  else if(val==1750) return 1;
}

//bool rh.returnHome(void);
//complex function which returns the drone home

void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
