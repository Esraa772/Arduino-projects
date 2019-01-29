   /*
  Smart Home
  Edited by Mohamed Okasha
  July, 2017
  */
  /*
  Library Source:
  Lego Advanced Kit 
  by Lego Electronics
  www.facebook.com/Legoelectronics
 */

/*Part1 Bush Putton to control a Servo Motor */
#include <Servo.h>
Servo myservo;
int buttonPin = 2;    // the number of the pushbutton pin
int buttonState = 0;  // variable for reading the pushbutton status
int servoPin =  3;   // the number of the Servo pin
int valOpen=90;     // cahnges according to the postion of servo relative to the door
int valClose=0;    // cahnges according to the postion of servo relative to the door

/*Part2 Read From Ultrasonic and get the output on a Buzzer*/
int distance;
#include "Ultrasonic.h"
Ultrasonic ultrasonic(11,10);//(Trig,Echo)

/*Part3 Read From DHT11 and display in Serial Monitor*/
#include <DHT11.h>
dht11 DHT11;
#define DHT11PIN 4

/*Part4 Light ON/OFF Acording to light falling on LDR*/  
int LDRpin = A0;
int LEDpin = 5;
int lightLevel;


void setup() {
	/*Part1 Bush Putton to control a Servo Motor */    
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  myservo.attach(servoPin);  

  /*Part2 Read From Ultrasonic and get the output on a Buzzer*/
	Serial.begin(9600);
  pinMode(9, OUTPUT);
  
}

void loop()
{
   /*Part1 Bush Putton to control a Servo Motor */
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
     myservo.write(valOpen);                  // sets the servo position according to the scaled value
     delay(15);                           // waits for the servo to get there
  } 
  else {
     myservo.write(valClose);                  // sets the servo position according to the scaled value
     delay(15);                           // waits for the servo to get 
  }

	/*Part2 Read From Ultrasonic and get the output on a Buzzer*/
	//output the distance in cm
	distance = Serial.println(ultrasonic.Ranging(CM)); 
	delay(100);
  if(distance<=15){
    digitalWrite(9, HIGH);
  }
/*Part3 Read From DHT11 and display in Serial Monitor*/
int chk = DHT11.read(DHT11PIN);

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK: 
    Serial.println("OK"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.println("Checksum error"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.println("Time out error"); 
    break;
    default: 
    Serial.println("Unknown error"); 
    break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);
  
/*Part4 Light ON/OFF Acording to light falling on LDR*/  
 lightLevel = analogRead(LDRpin);
 lightLevel = map(lightLevel, 0, 900, 0, 255);
 lightLevel = constrain(lightLevel, 0, 255);
 analogWrite(LEDpin, lightLevel);

  }



