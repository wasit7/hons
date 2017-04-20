#define D0 16
#define D4 2

void setup() {
  pinMode(D4, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (3.2 / 1023.0);
  Serial.println(voltage);
  digitalWrite(D4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(D4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
