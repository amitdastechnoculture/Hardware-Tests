#include "Utils.h"
#include "Serial.h"

inline void setup_motor_params(const long speed, const long acc){
  stepper.setMaxSpeed(speed);
  stepper.setAcceleration(acc);
}

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

void setup_base(){  
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  setup_driver();
  setup_motor_params(MAXSPEED, ACCELERATION); // <== Setup Max Speed and Acceleration

  setup_serial(); 
}
