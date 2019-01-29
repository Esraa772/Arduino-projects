//part 1 pushbutton to control a servo motor
#include <Servo.h>
Servo myservo;
int buttonPin=2;//the number of push button pin
int buttonState=0;//variable to read push button state
int servoPin=3;//the number of servo pin
int valOpen =90;//changes according to the servo position
int valClose =0;//the same 
void setup() {
  //part1 pushbutton to control servo part
  //initialize the buttonpin as an input 
  pinMode (buttonPin,INPUT);
  myservo.attach(servoPin);
}

void loop() {
  // part1 pushbutton to control servo part
  //read the state of the pushbutton :
  buttonState=digitalRead(buttonPin);
  /*check if the pushbutton is pressed 
  if it is , the push button state is HIGH*/
  if (buttonState==HIGH)
  {
    myservo.write(valOpen);
    delay(15);
    }
    else 
    {
      myservo.write(valClose);
      delay(15);
      }
}
