int led = 2;
unsigned char panic [8] = "01010101";
unsigned char configured [8] = "11111111";
unsigned char unconfigured [8] = "00000000";
void ledBlink(unsigned char* t);
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  delay(10);
}

void loop() {
  ledBlink(panic);
}

void ledBlink(unsigned char* t){
  for(int k = 0; k < 8; k++){
    digitalWrite(led, t[k]);
    delay(20);
  }
}
