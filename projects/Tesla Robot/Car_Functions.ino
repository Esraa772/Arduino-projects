//==============Pins and constants value=============//
#define N11  2//Motor"A"1 pin1 
#define N12  3//Motor"A"1 pin2
#define N13  4//Motor"B"1 pin1
#define N14  5//Motor"B"1 pin2 

#define N21  6//Motor"A"1 pin1 
#define N22  7//Motor"A"1 pin2
#define N23  8//Motor"B"1 pin1
#define N24  9//Motor"B"1 pin2 
int SPEED = 65;
//====================================================//


//================functions decleration===============// 
void Forwrd_car();
void Backward_car();
void Left_car();
void Right_car();
//=====================================================//

//=====================SETUP==========================//
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
}
//====================================================//

//====================LOOP===========================//
void loop() {
Forwrd_car();
/*delay(1000);
Backward_car();
delay(1000);
Left_car();
delay(1000);
Right_car();
delay(1000);*/
}
//===================================================//

//=================Definitions=======================//
void Forwrd_car()
{
  analogWrite(N11,SPEED+40); // MA1 pin1 HIGH
  analogWrite(N12,0); // MA1 pin2 LOW
  analogWrite(N13,0); //MB2 pin2 LOW
  analogWrite(N14,SPEED+40); // MB2 pin1 HIGH

  analogWrite(N21,SPEED-5); // MA1 pin1 HIGH
  analogWrite(N22,0); // MA1 pin2 LOW
  analogWrite(N23,0); //MB2 pin2 LOW
  analogWrite(N24,SPEED-5); // MB2 pin1 HIGH
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
