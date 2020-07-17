const int IN1 = PB7;
const int IN2 = PB6;
const int IN3 = PB5;
const int IN4 = PB13;
const int ENA = PB14;
const int ENB = PB12;


void setup() {

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
//  pinMode (ENB, OUTPUT);

}

void loop() {
//control speed 
  analogWrite(ENA, 255);
  analogWrite(ENB, 255); 
//control direction 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  

}
