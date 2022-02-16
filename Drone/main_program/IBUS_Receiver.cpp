#include <Arduino.h>

#include "IBUS_Receiver.h"
#include "FlySkyIBus_Decoder.h"

IBus_Receiver::IBus_Receiver(){
    for(int i=0; i<nr_of_channels; i++){
        self.channels[i].setChannelNr(i);
    }

    Serial.begin(115200);
    IBus.begin(Serial);
}

Channels1to4_read IBus_Receiver::readChannels1to4(void){
    IBus.loop();
    for(int i=0; i<4; i++){
        Channels1to4.arr[i] = self.channels[i].readValue();
    }
    return Channels1to4;
}

int IBus_Receiver::readChannel6(void){
    IBus.loop();
    return self.channels[5].readValue();
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

Channel::Channel(){
}

int Channel::readValue(void){
    self.read = IBus.readChannel(self.channelNr);
    return self.read;
}

void Channel::setChannelNr(int x){
    self.channelNr = x;
}

IBus_Receiver IBus_Receiver_Drone = IBUS_Receiver();