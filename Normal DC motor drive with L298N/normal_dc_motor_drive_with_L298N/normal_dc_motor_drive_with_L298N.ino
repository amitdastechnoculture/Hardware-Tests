const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 11;
const int IN4 = 12;
const int ENA = 7;
const int ENB = 10;


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
