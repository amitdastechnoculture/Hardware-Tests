const int transistor = 2;

void setup()
{
  pinMode (transistor, OUTPUT);
}

void loop()
{
  digitalWrite (transistor, HIGH);
  delay(1000);
  digitalWrite (transistor, LOW);
  delay(1000);
}
