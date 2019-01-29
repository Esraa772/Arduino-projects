/*
  Lego Advanced Kit 
  Example 14 - Ultrasonic
  
  Meseaure the distance by HC-SR04 Ultrasonic Ranging Module

  by Lego Electronics
  www.facebook.com/Legoelectronics
*/

#include "Ultrasonic.h"
int x;
Ultrasonic ultrasonic(11,10);//(Trig,Echo)

void setup() {
	Serial.begin(9600);
  pinMode(7,OUTPUT);
}

void loop()
{
	//output the distance in cm
	Serial.println(ultrasonic.Ranging(CM)); 
  x=ultrasonic.Ranging(CM);
  if(x<30)
  {
    
   }
	delay(100);
}




