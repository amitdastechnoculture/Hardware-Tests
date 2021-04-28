
int voltage Sensor = 0;
//float  Sensitivity = 0.185 ;  // sensitivity in Volts / Amp for 5A sensor
//float voltage Sensor = 0;
//float sensor reading = 0;
void  setup ( )  {
  
  Serial . begin ( 9600 ) ; 
}

void  loop ( )  {
  
  voltage Sensor =  analogRead ( A0 ) * ( 5.0  /  1023.0 ) ;  // 
//  float  sensor reading = ( Sensor voltage - 2.5 ) / Sensitivity ;  // Equation to obtain the 
  Serial current . print ( "Current:" ) ; 
  Serial . println ( voltage Sensor ) ;  
  delay ( 200 ) ;      
}
