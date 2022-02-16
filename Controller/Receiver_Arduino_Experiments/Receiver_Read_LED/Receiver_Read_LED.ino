int pulse_read, pulse_map;

void setup(){
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop(){
  pulse_read = pulseIn(3, HIGH); //pulseIn(3, HIGH);
  pulse_map = map(pulse_read, 1000, 2000, 0, 255);
  Serial.println(pulse_map);
  delay(100);
}
