#include <Servo.h>
#include <Ultrasonic.h>
Servo s;
Ultrasonic ult (10,11); // trig , echo 

#define l1 5 //left motor
#define r1 6 // right motor
#define l2 8 //left motor
#define r2 9 // right motor
//#define max_dis 200
bool gf = 0; // goes forward 
int distance = 100;




void setup() {
  // put your setup code here, to run once:
pinMode(l1,OUTPUT);
pinMode(r1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(r2,OUTPUT);
s.attach(12);

s.write(150);
delay(2000);
distance = ult.Ranging(CM);
Serial.begin(9600);
Serial.println(distance);
delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
int dr = 0; // distance right
int dl = 0; // distance left 

delay(50);

if (distance <= 20 )
{
  ms(); //call the move stop function 
  delay (300);
  mb(); //call the move backward function 
  delay (400);
  ms();
  delay(300);
  dr = lr(); // distance right => look right  
  delay (300);
  dl = ll(); // distance left => look left 
  delay (300);

  if (distance >= dl)
  {
    turn_right();
    ms();
  }
  else 
  {
    turn_left();
    ms();
  }
}
else 
{
  mf(); // move forward 
}
distance = ult.Ranging(CM);
}

//******************************************//
void ms()
{
  digitalWrite(l1,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r2,LOW);
}

//*******************
void mb()
{
  gf=false;
  digitalWrite(l1,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(r2,LOW);
}

void mf()
{
  if(!gf)
  {
    gf=true;
    digitalWrite(l1,HIGH);
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(l2,LOW);
  }
}
//********************

int lr()
{
  s.write(50);
  delay(500);
  int dist = ult.Ranging(CM);
  Serial.println(dist);
  delay(100);
  s.write(115);
  return dist ;
}

int ll()
{
  s.write(170);
  delay(500);
  int dista = ult.Ranging(CM);
  Serial.println(dista);
  delay(100);
  s.write(115);
  return dista ; 
}

//**********************************

void turn_right()
{
  digitalWrite(l1,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(r2,LOW);

  delay(500);
  digitalWrite(l1,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r2,HIGH);
  
}

void turn_left()
{
  digitalWrite(l1,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r2,HIGH);

  delay(500);
  digitalWrite(l1,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r2,HIGH);
  
}

