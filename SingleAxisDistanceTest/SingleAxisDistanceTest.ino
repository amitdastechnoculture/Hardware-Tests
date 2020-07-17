#define DEBUG

//#include <Encoder.h>
//Encoder myEnc(39, 3);

//#define ADC_PIN 3
//#define PWM_PIN 7

#define INITIAL_DELAY 10000

unsigned long initial_time = 0;
long oldPosition  = -999;

/* PARAMETERS */
#define MINSPEED 10
#define MINACCELERATION 10
#define SHORT_DURATION 10000UL //(500 * 16) * 1); // ==> 200 for the stepper's original steps/revolution, 16 is the microsteps and 1 is the number of turns
/* END PARAMETERS */

/* PINS */
#define EN_PIN PB9     // LOW: Driver enabled. HIGH: Driver disabled
#define STEP_PIN PB8      // Step on rising edge
#define DIR_PIN PB13
/* END PINS */

/* LIBRARY INCLUDES */
#include <TMC2208Stepper.h>
#include <AccelStepper.h>
/* END LIBRARY INCLUDES */

/* GLOBAL VARIABLES */
TMC2208Stepper driver = TMC2208Stepper(&Serial);
AccelStepper stepper(1, STEP_PIN, DIR_PIN);

enum Direction {
  OUTWARDS = -1,
  INWARDS = 1
};

enum State {
  MOVE = 1,
  STOP
};

// STATE -----------------------
volatile State  motor_state        = MOVE;
volatile Direction motor_direction = INWARDS;
// -----------------------------

void setup_driver(){
  digitalWrite(EN_PIN, HIGH);
  
  driver.pdn_disable(1);              // Use PDN/UART pin for communication
  driver.mstep_reg_select(1);   // TRYING TO SET THE MICROSTEPS LIKE THIS, BUT TO NO AVAIL!!
  driver.microsteps(0);
  driver.I_scale_analog(0);           // Adjust current from the registers
  driver.rms_current(500);            // Set driver current 500mA
  driver.toff(0x2);               // Enable driver
  
  digitalWrite(EN_PIN, LOW); // Enable driver
}

void setup_motor_params(){
  stepper.setMaxSpeed(MINSPEED);
  stepper.setAcceleration(MINACCELERATION);
}

void setup() {
  Serial.begin(115200);
//  Serial.println("CLEARDATA");
//  Serial.println("CLEARDATA");
//  Serial.println("LABEL,Time,Start Time,Distance sensor Value,Encoder Value");
//  Serial.println("RESETTIMER");
//  pinMode(ADC_PIN, INPUT);
//  pinMode(PWM_PIN, OUTPUT);
//  analogReadResolution(12);
  
//  analogWrite(PWM_PIN, 255);

  initial_time = millis();
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  setup_driver();
  setup_motor_params();
  
  delay(10000);
}

void loop() {
//    if( millis() - initial_time > INITIAL_DELAY ){ 
//    Serial.print("DATA,TIME,TIMER,");
//    Serial.print(analogRead(ADC_PIN)); Serial.print(",");
//    delay(1);
//  }
  
//  long newPosition = myEnc.read();
  
//  if (newPosition != oldPosition) {
//    oldPosition = newPosition;
//    Serial.println(newPosition);
//    delay(3);

//    if(newPosition >= 70000){
//      stepper.stop();
    }
//  }

//  stepper.moveTo(-1* SHORT_DURATION);
  stepper.run();
}
