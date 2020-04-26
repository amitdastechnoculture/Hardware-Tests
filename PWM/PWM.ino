#define DUTYCYCLE 20 // 0, 20, 40, 60, 80, 100


// ==================================================
#define ANALOG_DUTYCYCLE int(DUTYCYCLE*2.55)

void setup() {  
  Serial.begin(9600);
  delay(2000);
  Serial.println(DUTYCYCLE);
  Serial.println(ANALOG_DUTYCYCLE);
  pinMode(2, OUTPUT);
}

void loop() {
  analogWrite(2, ANALOG_DUTYCYCLE);
}
// ==================================================
