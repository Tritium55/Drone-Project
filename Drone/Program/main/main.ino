#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4
#define CH6 6

int pulse_read_CH1, pulse_read_CH2, pulse_read_CH3, pulse_read_CH4;
int pulse_read_CH6;
int pulse_map_CH1, pulse_map_CH2, pulse_map_CH3, pulse_map_CH4;
int pulse_map_CH6;

void readChannels(int lowChannel, int highChannel);
//reads all channels between lowChannel and highChannel including both and saves the read values to global vars
void writeMotors(void);
//converts mapped values and writes them to the ESC
void mapReads(int lowChannel, int highChannel);
//maps all read values from function void readChannels
int evaluateCh6(void);
//returns 0, 1 or 2 depending on which value is currently mapped on pulse_map_CH6
bool returnHome(void);
//complex function which returns the drone home

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
