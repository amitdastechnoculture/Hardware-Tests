#include "Utils.h"
#include "MotorSetup.h"
#include "Serial.h"

void limitswitch_ISR(){ 
  if(freespace >= 1000){
    freespace = -1;
    process_command(COMMAND_STOP);
  }
}

void setup_initial_condition(){
  #ifdef DEBUG
  process_command(COMMAND_MOVE_OUT);
  #else
  process_command(COMMAND_STOP);
  #endif
}

void setup_interrupts(){
  attachInterrupt(digitalPinToInterrupt(LIMITSWITCH1_PIN), limitswitch_ISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(LIMITSWITCH2_PIN), limitswitch_ISR, FALLING);
}

void setup_all(){
  setup_base();
  setup_interrupts();

  #ifdef DEBUG
  show_splash_screen();
  #endif
  setup_initial_condition(); // <== SETUP INITIAL STATE
}

void Move(){
  stepper.setMaxSpeed(max_speed);
  stepper.moveTo((long)motor_direction * LONG_DURATION);
  stepper.run();
  freespace++;
}

void Stop(){ stepper.stop(); }//Serial.println((long)motor_direction * (long)LONG_DURATION); }
