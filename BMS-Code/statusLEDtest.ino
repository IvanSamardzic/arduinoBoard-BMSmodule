int led = 2;
unsigned char panic [8] = {0,1,0,1,0,1,0,1};
unsigned char configured [8] = {1,1,1,1,1,1,1,1};
unsigned char unconfigured [8] = {0,0,0,0,0,0,0,0};
void ledBlink(unsigned char* t);
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  delay(10);
}

void loop() {
  ledBlink(panic);
  //ledBlink(unconfigured);
  //ledBlink(configured);
}

void ledBlink(unsigned char t[]){
  for(int k = 0; k < 8; k++){
    digitalWrite(led, t[k]);
    delay(100);
  }
}
