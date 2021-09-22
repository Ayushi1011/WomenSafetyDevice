#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

    
char logitude[10];
char latitude[10];

//int Ctrl+z=26; //for sending msg
const int LED_RB = 6;

void setup()
{
 lcd.begin(16,2);
 Serial.begin(4800);
pinMode(LED_RB, OUTPUT);

 lcd.setCursor(0,0);
 lcd.print("WOMEN SAFETY");
 lcd.setCursor(0,1);
 lcd.print("ALERT SYSTEM");
 delay(3000);
}
void loop()
{
 digitalWrite(LED_RB, HIGH); // turn the LED on (HIGH is the voltage level)
 delay(100); // wait for a second
// digitalWrite(LED_RB, LOW); // turn the LED off by making the voltage LOW
// delay(100);

 lcd.setCursor(0,0); //display latitude and longitude on 16X2 lcd display
 lcd.print("Lat(N)=18.515800");
 lcd.print(latitude);
 lcd.setCursor(0,1);
 lcd.print("Lon(E)=73.927200");
 lcd.print(logitude);
 delay(1000);


 lcd.clear();
 lcd.print("Sending SMS");
 Serial.begin(9600);
Serial.println("AT+CMGF=1"); //select text mode
 delay(10);
 Serial.println("AT+CMGS=\"91**********\""); // enter receipent number
 Serial.println("Danger Alert:");
 Serial.print("PLEASE HELP ME!!!!"); //enter message
 Serial.print("I am in danger "); 
 Serial.println("     "); 
Serial.println("Lon(E)=73.927200"); //enter longitude value in msg
Serial.println("Lan(N)=18.515800");
Serial.print("https://maps.app.goo.gl/txKo7NWiz3cD2rsy7");

lcd.clear();
lcd.print("SMS Sent");
  delay(20000);                        // next reading within 20 seconds
    Serial.begin(4800);
 }
