int pulse_read, pulse_map;

void setup(){
  pinMode(3, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  pulse_read = pulseIn(3, HIGH, 25000); //pulseIn(3, HIGH);
  pulse_map = map(pulse_read, 1000, 2000, 0, 255);
  Serial.println(pulse_map+2);
  if(pulse_map>125) digitalWrite(LED_BUILTIN, HIGH);
}
