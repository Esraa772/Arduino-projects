#include <Password.h>
#include <Keypad.h>
#include <Servo.h>
Servo myservo; // declare servo
Password password = Password ("123456789");//set password 

const byte rows =4;
const byte cols=4;
char keys [rows][cols]={ //define the keymap
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
  //connect keypad row 0,row 1,row 2,row 3 to these pins
  byte rowpins[rows]={4,5,6,7};
  //connect keypad col 0,col 1 ,col 2,col 3 to these pins 
  byte colpins[cols]={8,10,11,12};
//creat keypad 
  Keypad keypad =Keypad(makeKeymap(keys),rowpins,colpins,rows,cols);
  
void setup() {
  Serial.begin(9600);
  Serial.write(254);
  Serial.write (0x01);
  delay (200);
  pinMode (2,OUTPUT);//green light
  pinMode (12,OUTPUT);//red led 
  myservo.attach(13);//servo on digital pin 9 
  keypad.addEventListener(keypadEvent);
}

void loop() {
  keypad.getKey();
  myservo.write(0);
}
void keypadEvent(KeypadEvent eKey)
{
  switch(keypad.getState())
  {
    case PRESSED:
    Serial.print("Enter: ");
    Serial.println(eKey);
    delay(10);

    Serial.write(254);
    switch(eKey)
    {
      case 'A':checkPassword();delay(1);break;
      case 'B':password.reset();delay(1);break;
      default : password.append(eKey); delay(1);
      }
    }
}
void checkPassword(){
  if (password.evaluate()){
    Serial.println("Accepted");
    Serial.write(254);delay (10);
    myservo.write(5);//160deg and open the door 
    digitalWrite(2,HIGH);//turn on green led 
    delay(500);
    digitalWrite(11,LOW);//turn off red led 
    
  }
  else {
    Serial.println("Denied");//if passsword wrong
    Serial.write(254);delay(10);
    myservo.write(0);//don't open the door 
    digitalWrite(12,HIGH);//turn on red led 
    delay(500);
    digitalWrite(2,LOW);//turn off green led 
    }
  }
