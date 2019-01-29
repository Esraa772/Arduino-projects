#include <RedBot.h>
RedBotSensor IRSensor1 = RedBotSensor(A0);// initialize a sensor object on A0
RedBotSensor IRSensor2 = RedBotSensor(A1);
RedBotSensor IRSensor3 = RedBotSensor(A2);
int R1,R2,R3;

void setup() {
  // put your setup code here, to run once:
pinMode (5,OUTPUT);
pinMode (6,OUTPUT);
pinMode (9,OUTPUT);
pinMode (3,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(IRSensor1.read());
Serial.println(IRSensor2.read());
Serial.println(IRSensor3.read());
R1=IRSensor1.read();
R2=IRSensor2.read();
R3=IRSensor3.read();
if (R1>700&&R2>700&&R3>700) {
left();forward();
  }
  else if (R1<700&&R2>700&&R3>700) {
    
    }
  else if (R1>700&&R2<700&&R3>700) {
    
    }
  else if (R1>700&&R2>700&&R3<700) {
    
    }
  else if (R1>700&&R2<700&&R3<700) {
    
    }
  else if (R1<700&&R2>700&&R3<700) {
    
    }
  else if (R1<700&&R2<700&&R3>700) {
    
    }
  else if (R1<700&&R2<700&&R3<700) {
    
    }
}
void forward ()
{
  analogWrite(5,100);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(3,100);
  }
  void stop_m()
  {
    analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(3,0);
    }
    void right()
    {
      analogWrite(5,100);
  analogWrite(6,0);
  analogWrite(9,100);
  analogWrite(3,0);
      }
      void left()
      {
        analogWrite(5,0);
  analogWrite(6,100);
  analogWrite(9,0);
  analogWrite(3,100);
        }

