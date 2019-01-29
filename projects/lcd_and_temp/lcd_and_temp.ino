/* 
  Lego Advanced Kit
  Example 10 - HumAndTempSensor
  
  Get the humidity and temperature value from DHT11,
  and display it on the Serial Monitor.
  
  by Lego Electronics
  www.facebook.com/Legoelectronics
*/

#include <DHT11.h>

dht11 DHT11;

#define DHT11PIN 8
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2,3,4,5,6,7);

void setup()
{
  
  lcd.begin(16,2);
}

void loop()
{
  lcd.setCursor (1,0);
  lcd.write("Temp Sensor ");
  lcd.setCursor (4,1);
  lcd.write("Test :)!");
   delay(5000);
 lcd.clear();
 lcd.setCursor(0,0);
  lcd.write("Read sensor: ");
   int chk = DHT11.read(DHT11PIN);
   delay(3000);
  lcd.clear();
  /*switch (chk)
  {
    case DHTLIB_OK: 
    {lcd.clear();
    lcd.write("OK"); 
    break;}
    case DHTLIB_ERROR_CHECKSUM: 
    {lcd.clear();
    lcd.write("Checksum error"); 
    break;}
    case DHTLIB_ERROR_TIMEOUT: 
    {lcd.clear();
    lcd.write("Time out error"); 
    break;}
    default: 
    {lcd.clear();
    lcd.write("Unknown error"); 
    break;}
  }*/
  lcd.setCursor(0,0);
  lcd.write("Humidity:");
  lcd.print((float)DHT11.humidity, 2);
  lcd.setCursor(0,1);
  lcd.write("Temperature:");
  lcd.print((float)DHT11.temperature, 2);
  delay(4000);
  lcd.clear();
  
}
