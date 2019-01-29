#include <RedBot.h>
RedBotSensor IRSensor1 = RedBotSensor(A0);// initialize a sensor object on A0
RedBotSensor IRSensor2 = RedBotSensor(A1);
RedBotSensor IRSensor3 = RedBotSensor(A2);
int R1,R2,R3;
#define m11 2
#define m12 3
#define m21 4
#define m22 5
void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to experiment 6!");
  Serial.println("------------------------");
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
}

void loop()
{
  Serial.print("IR Sensor Readings: ");                                                                       
  Serial.print(IRSensor1.read()); 
  Serial.println();
  //delay(100);
  R1=IRSensor1.read();
  R2=IRSensor1.read();
  R3=IRSensor1.read();
 /* while(if(R1>700&&R2>700&&R3>700))
  {
    forward(m11,m12);
    forward(m21,m22);
  }*/
  int x=GetRoad();
  switch(x)
  {
    case 2:break;
    case 3:break;
    case 4:break;
    case 5:break;
    case 6:break;
    case 7:
    case 8:
    case 9:
    }
  .
}
int GetRoad()
{
  if (R1>700&&R2>700&&R3>700) return 2;
  else if (R1<700&&R2>700&&R3>700) return 3;
  else if (R1>700&&R2<700&&R3>700) return 4;
  else if (R1>700&&R2>700&&R3<700) return 5;
  else if (R1>700&&R2<700&&R3<700) return 6;//left
  else if (R1<700&&R2>700&&R3<700) return 7;//forward
  else if (R1<700&&R2<700&&R3>700) return 8;//right
  else if (R1<700&&R2<700&&R3<700) return 9;
  }
void forward(int x,int y)
{
  digitalWrite(x,HIGH);
  digitalWrite(y,LOW);
  
  }
  void reverse(int x,int y)
{
  digitalWrite(y,HIGH);
  digitalWrite(x,LOW);
  
  }
  void stop_m(int x,int y)
{
  digitalWrite(x,LOW);
  digitalWrite(y,LOW);
 
  }

