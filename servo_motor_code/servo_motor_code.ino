#include <Servo.h>

Servo myservo;                 // providing a name

int angle = 0;                     // variable to store the servo position

void setup() {
  myservo.attach(2);        // attaches the servo on pin 2 to the servo object
}

void loop() {
  for (angle = 0; angle <= 180; angle += 1) {     // goes from 0 degrees to 180 degrees, in steps of 1 degree
    myservo.write(angle);                                     // tell servo to go to position in variable 'angle'
    delay(15);                                                        // waits 15ms for the servo to reach the position
  }
  for (angle = 180; angle >= 0; angle -= 1) {     // goes from 180 degrees to 0 degrees
    myservo.write(angle);              
    delay(15);                                                       // waits 15ms for the servo to reach the position
  }
}
