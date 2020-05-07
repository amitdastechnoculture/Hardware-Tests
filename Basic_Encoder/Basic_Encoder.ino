@ -0,0 +1,16 @@
#include <Encoder.h>
Encoder myEnc(39, 3);

long oldPosition  = -999;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
}
