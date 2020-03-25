//==================LIBRARIES============================//
#include <SoftwareSerial.h>
#include <Ultrasonic.h>
//=====================================================//

//======================OBJECTS==========================//
SoftwareSerial bt(50,51); // tx , rx
Ultrasonic right_ult(26,27);
Ultrasonic left_ult(22,23);
Ultrasonic front_ult(24,25);
//=====================================================//

//==========MACROS & CONSTANTS & VARIABLES=============//
#define N11  2//Motor"A"1 pin1 
#define N12  3//Motor"A"1 pin2
#define N13  4//Motor"B"1 pin1
#define N14  5//Motor"B"1 pin2 

#define N21  6//Motor"A"2 pin1 
#define N22  7//Motor"A"2 pin2
#define N23  8//Motor"B"2 pin1
#define N24  9//Motor"B"2 pin2 
int SPEED = 65;
char data;
//====================================================//

//================functions decleration===============// 
void Forward_car();
void Backward_car();
void Left_car();
void Right_car();
//=====================================================//

//=======================SETUP========================//
void setup() {
  // put your setup code here, to run once:
pinMode(N11,OUTPUT);
pinMode(N12,OUTPUT);
pinMode(N13,OUTPUT);
pinMode(N14,OUTPUT);

pinMode(N21,OUTPUT);
pinMode(N22,OUTPUT);
pinMode(N23,OUTPUT);
pinMode(N24,OUTPUT);

bt.begin(9600);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(bt.available() !=0) //check connectivity 
{
   data = bt.read();
   Serial.println(data);
   if(data == 'F') //forward 
   {
    Forward_car();
   }
   else if(data == 'B') //baackward 
   {
    Backward_car();
   }
   else if(data == 'L') //left
   {
    Left_car();
   }
   else if(data == 'R') //right
   {
    Right_car();
   }
   else 
   {
    stop_car();
   }
}
else
{
  Forward_car();
  if(front_ult.read()<16)
  {
    stop_car();
    if(left_ult.read()>16 && left_ult.read() > right_ult.read())
    {
      Left_car();
      //Delay.......
      Forward_car();
      
    }
    else if(right_ult.read()>16 && left_ult.read() < right_ult.read())
    {
      Right_car();
      //Delay........
      Forward_car();
    }
    else
    {
      Right_car();
      //Delay........but double
      Forward_car();
    }
  }
}
}


//=================Definitions=======================//

void Forward_car()
{
  analogWrite(N11,SPEED); // MA1 pin1 HIGH
  analogWrite(N12,0); // MA1 pin2 LOW
  analogWrite(N13,0); //MB2 pin2 LOW
  analogWrite(N14,SPEED); // MB2 pin1 HIGH

  analogWrite(N21,SPEED); // MA1 pin1 HIGH
  analogWrite(N22,0); // MA1 pin2 LOW
  analogWrite(N23,0); //MB2 pin2 LOW
  analogWrite(N24,SPEED); // MB2 pin1 HIGH
}

void Backward_car()
{
  analogWrite(N11,0); // MA1 pin1 LOW
  analogWrite(N12,SPEED); // MA1 pin2 HIGH
  analogWrite(N13,SPEED); //MB2 pin2 HIGH
  analogWrite(N14,0); // MB2 pin1 LOW

  analogWrite(N21,0); // MA1 pin1 LOW
  analogWrite(N22,SPEED); // MA1 pin2 HIGH
  analogWrite(N23,SPEED); //MB2 pin2 HIGH
  analogWrite(N24,0); // MB2 pin1 LOW
  
}
void Right_car()
{
 analogWrite(N11,SPEED);
 analogWrite(N12,0);
 analogWrite(N13,SPEED);
 analogWrite(N14,0);

 analogWrite(N21,0);
 analogWrite(N22,SPEED);
 analogWrite(N23,0);
 analogWrite(N24,SPEED);
}
void Left_car()
{
 analogWrite(N11,0);
 analogWrite(N12,SPEED);
 analogWrite(N13,0);
 analogWrite(N14,SPEED);

 analogWrite(N21,SPEED);
 analogWrite(N22,0);
 analogWrite(N23,SPEED);
 analogWrite(N24,0); 
}
void stop_car()
{
  analogWrite(N11,0);
 analogWrite(N12,0);
 analogWrite(N13,0);
 analogWrite(N14,0);

 analogWrite(N21,0);
 analogWrite(N22,0);
 analogWrite(N23,0);
 analogWrite(N24,0); 
}
