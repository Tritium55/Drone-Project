#include <Arduino.h>

#include "IBUS_Receiver.h"
#include "FlySkyIBus_Decoder.h"

IBus_Receiver::IBus_Receiver(){
    Serial.begin(115200);
    FlySkyIBus.begin(Serial);
}

void IBus_Receiver::readChannels1to4(void){

}

void IBus_Receiver::readChannel6(void){

}


class Channel{
    private:
        int read;
        int channelNr;
    public:
        Channel();
        int readValue(void);
        void setChannelNr(int x);
}

int Channel::readValue(void){
    self.read = FlySkyIBus.readChannel(self.channelNr);
}

void Channel::setChannelNr(int x){
    self.channelNr = x;
}

IBus_Receiver IBus_Receiver_Drone = IBUS_Receiver();