int ntc = A0;

void setup(){
  Serial.begin(9600);
  pinMode(ntc, INPUT);
}

void loop(){
  /*int analogValue = analogRead(ntc);
  double voltageValue = double(analogValue) * 5.0 / 1023;
  Serial.print("Value: ");
  Serial.print(analogValue);
  Serial.print(" ");
  Serial.print("Voltage: ");
  Serial.print(voltageValue);
  Serial.println(" V");
  */
  float temperature = calculateTemp(ntc);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000);
}

float calculateTemp(int ThermistorPin){
  int analogValue;
  float R1 = 10000;
  float logR2, R2, T, Tc, Tf;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
  analogValue = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)analogValue - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  return Tc;
}
