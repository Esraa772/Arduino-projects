#include <Servo.h>
Servo servo1,servo2,servo3;
int x,y,z;
#define p1 A0
#define p2 A1
#define p3 A2
void setup() {
  // put your setup code here, to run once:
servo1.attach(9);
servo2.attach(10);
servo3.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
x=analogRead(p1);
y=analogRead(p2);
z=analogRead(p3);
x=map(x,0,1023,0,180);
y=map(y,0,1023,0,180);
z=map(z,0,1023,0,180);
servo1.write(x);
servo2.write(y);
servo3.write(z);
}
