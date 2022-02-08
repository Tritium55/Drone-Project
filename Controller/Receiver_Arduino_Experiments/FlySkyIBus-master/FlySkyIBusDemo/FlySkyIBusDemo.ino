/*
 * Test FlySky IBus interface on an Arduino Mega.
 *  Connect FS-iA6B receiver to Serial1.
 */
 
#include "FlySkyIBus.h"

void setup(){
  Serial.begin(115200);
  IBus.begin(Serial);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){

  IBus.loop();
  delay(40);
  
  Serial.print("CH1 ") ;
  Serial.println(IBus.readChannel(5));
//  Serial.println("CH2 ") ;
//  Serial.println(IBus.readChannel(1), DEC);
//  Serial.println("CH3 ") ;
//  Serial.println(IBus.readChannel(2), DEC); 
//  Serial.println("CH4 ") ;
//  Serial.println(IBus.readChannel(3), DEC); 
//  Serial.println("CH5 ") ;
//  Serial.println(IBus.readChannel(4), DEC);
//  Serial.println("CH6 ") ;
//  Serial.println(IBus.readChannel(5), DEC);
//  Serial.println("CH7 ") ;
//  Serial.println(IBus.readChannel(6), DEC); 
//  Serial.println("CH8 ") ;
//  Serial.println(IBus.readChannel(7), DEC);
//  Serial.println("CH9 ") ;
//  Serial.println(IBus.readChannel(8), DEC); 
//  Serial.println("CH10 ") ;
//  Serial.println(IBus.readChannel(9), DEC);
//  delay(3000);
}
