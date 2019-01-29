#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <Servo.h>
#include <LiquidCrystal.h>
//#include "Ultrasonic.h"

Ultrasonic ultrasonic(29,30);


LiquidCrystal lcd(22,23,24,25,26,27); //rs,e,d4...d7
int pos=0;
Servo servo1;
Servo servoroom; 
//void checkPassword();

int ledG = 11;
int ledR = 12; 
int buzz =10; 
Password password = Password( "1234" );

const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 2,3,4,5 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 6,7,8,9 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
        


  Serial.begin(9600);
  lcd.begin(16,2);
//lcd.clear();
   lcd.setCursor(0,0);

    lcd.print("Enter password");

  keypad.addEventListener(keypadEvent); //add an event listener for this keypad

servo1.attach(13);
servo1.write(10);
//delay(500);

pinMode(ledG, OUTPUT);
pinMode(ledR , OUTPUT);
pinMode(buzz,OUTPUT);
servoroom.attach(28);
}

void loop(){
 // lcd.setCursor(0,1);
//lcd.clear();
//lcd.setCursor(1,0);

  keypad.getKey();

 // int i=ultrasonic.Ranging(CM);
  //Serial.println(i);
  //if(i<=10){
  // servoroom.write(180); 
  //}
 // else
//{
  //servoroom.write(0);
 // } 
  delay(100);
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
  Serial.print("Pressed: ");
  Serial.println(eKey);
  //lcd.setCursor(0,1);
  //lcd.print(eKey);
  
  switch (eKey){
    case '*': checkPassword(); break;
    case '#':{ password.reset();
    servo1.write(10);
   // delay(500);
    digitalWrite(buzz,LOW);
    digitalWrite (ledG, LOW);
    digitalWrite(ledR,LOW);

      pos = 0;
    lcd.clear();
          lcd.setCursor(0,0);

    lcd.print("Enter password");
    //delay(1000);
    
   break; }  
    default:{ 
      
      password.append(eKey);
      lcd.setCursor(pos,1);
      lcd.print("*");
    pos++;
    if(pos == 4)
    {
      pos = 0;
    }
    }
    };
     }
  }


void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
    servo1.write(180);
    delay(500);
    digitalWrite (ledG, HIGH);
    lcd.clear();
              lcd.setCursor(1,0);

    lcd.print("Welcome ");
    
    //delay(1000);
    //Add code to run if it works
  }else{
    Serial.println("Wrong");
    digitalWrite(ledR,HIGH);
    digitalWrite(buzz,HIGH);

    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Amsk 7ramaaaaay");
    //add code to run if it did not work
  }
}
