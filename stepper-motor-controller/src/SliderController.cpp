#include <Arduino.h>
#include "SliderController.h"

void setup(){ setup_all(); }

void loop(){
   if(Serial.available()) { process_command(Serial.parseInt()); } // IF THERE IS A COMMAND => PROCESS IT
   
   switch(motor_state){
    case STOP: Stop(); break;
    case MOVE: Move(); break;
    case IDLE: break;
    default:   break;
   }
}
