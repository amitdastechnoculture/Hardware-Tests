/*
AD7193_VoltageMeasure_Example

Signal Connections:
-----------------------------------------------------
 Signal Name |  PmodAD Pin  |  Arduino Pin 
-----------------------------------------------------
  ~CS        |  J1, Pin 1   |  10
  MOSI       |  J1, Pin 2   |  MOSI or 11 or ICSP-4
  MISO       |  J1, Pin 3   |  MISO or 12 or ICSP-1
  SCLK       |  J1, Pin 4   |  SCLK or 13 or ICSP-3
  GND        |  J1, Pin 5   |  GND
  VCC (3.3V) |  J1, Pin 6   |  3.3V
-----------------------------------------------------
-----------------------------------
 Signal Name       |  PmodAD5 Pin    
-----------------------------------
 Channel 1 Pos     |  J2, Pin 3
 Channel 1 Neg     |  J2, Pin 4
-----------------------------------
See Table 24 of AD7193 datasheet for more information
*/

#include <SPI.h>
#include <AD7193.h>

#define ADC_PIN 3
#define PWM_PIN 7

AD7193 AD7193;

void Init_AD7193(void)
{
  AD7193.begin(); // initialization of Pmod AD5 module
  AD7193.AppendStatusValuetoData(); // configuration of Pmod AD5 module
  AD7193.SetPGAGain(1);
  AD7193.SetAveraging(100);
  AD7193.Calibrate();
  AD7193.ReadRegisterMap();
}

void setup() {
  pinMode(ADC_PIN, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  analogWrite(PWM_PIN, 255);
  
  Init_AD7193();
  Serial.begin(115200);
}

void loop() {
  float ch1Voltage;
  ch1Voltage = AD7193.DataToVoltage(
    AD7193.ReadADCChannel(1) >> 8);
  Serial.println(ch1Voltage*10000, 2);  
   
  delay(3);
}
