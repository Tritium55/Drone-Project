#ifndef IBUS_Receiver
#define IBUS_Receiver

#define nr_of_channels 6        //defining the number of channels

class IBus_Receiver{
    private:
        Channel channels = [nr_of_channels];
    public:
        IBus_Receiver();
        void readChannels1to4(void);
        void readChannel6(void);
        void loop(void);
}

extern IBUS_Receiver IBus_Receiver_Drone;

#endif