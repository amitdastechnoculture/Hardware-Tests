#define ADC_PIN 3
#define PWM_PIN 7

#define INITIAL_DELAY 10000

unsigned long initial_time = 0;
//
//int smooth(){
//  int value = 0;
//  int numReadings = 2;
//
//  for (int i = 0; i < numReadings; i++){
//    value = value + analogRead(ADC_PIN); // Read light sensor data
//    delay(1); // 1ms pause adds more stability between reads
//  }
//  value = value / numReadings; // Take an average of all the readings
//
//  return value;
//}

void setup(){
  Serial.begin(9600);

  Serial.println("CLEARDATA");
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Start Time,Value");
  Serial.println("RESETTIMER");
  
  pinMode(ADC_PIN, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  analogReadResolution(12);
  
  analogWrite(PWM_PIN, 255);

  initial_time = millis();
}

void loop(){ 
  if( millis() - initial_time > INITIAL_DELAY ){ 
    Serial.print("DATA,TIME,TIMER,");
    Serial.println(analogRead(ADC_PIN)); 
    delay(1);
  }
}
