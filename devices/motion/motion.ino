#define D0 16
#define D3 0
#define D4 2
volatile unsigned long ti=0;
byte x=0,xprev=0;
void setup() {
  pinMode(D4, OUTPUT);
  pinMode(D3, INPUT);
  attachInterrupt(digitalPinToInterrupt(D3), alarm, RISING);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
//check rising edge of alarm signal
  x=millis()-ti < 7000;
  if( x && !xprev){
    Serial.println("Alarm!!");
    Serial.println(x);
    Serial.println(xprev);
  }
  xprev=x;

//set LED
  digitalWrite(D4, !x); //LOW LED ON
  //digitalWrite(D4, !digitalRead(D3));
}

void alarm() {
  ti = millis(); 
  Serial.println(ti); 
}
