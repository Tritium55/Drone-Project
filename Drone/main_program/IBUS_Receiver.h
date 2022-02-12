#ifndef IBUS_Receiver
#define IBUS_Receiver

#define nr_of_channels 6        //defining the number of channels

class IBus_Receiver{
    private:
        Channel channels = [nr_of_channels];
    public:
        IBus_Receiver();
        Channels1to4_read readChannels1to4(void);
        int readChannel6(void);
        void loop(void);
}

typedef struct Channels1to4_read{
    int arr[4];
}

extern IBUS_Receiver IBus_Receiver_Drone;

#endif