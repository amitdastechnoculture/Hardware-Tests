void setup() {
Serial.begin(9600);
}

void loop() {
Serial.print(analogRead(A0));
Serial.print(" ");
Serial.println(analogRead(A2));
//Serial.print(" ");

//Serial.println(analogRead(A3));
//Serial.println(analogRead(A4));
//Serial.println();
delay(1000);
}
