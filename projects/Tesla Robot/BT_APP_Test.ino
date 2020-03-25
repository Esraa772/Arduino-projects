#include <SoftwareSerial.h>
SoftwareSerial bt(50,51);//tx , rx
String data="";
float x;
void setup() {
  // put your setup code here, to run once:
bt.begin(9600);
Serial.begin(9600);
//while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }
}

void loop() {
  // put your main code here, to run repeatedly:
if(bt.available()!=0)
{
//  data="";
//  data=bt.readString();
//  Serial.println(data);
  x=bt.read();
  Serial.println(x);

}
}
