
#define BLYNK_TEMPLATE_ID "Blynk Id"
#define BLYNK_TEMPLATE_NAME "Blynk Name"
#define BLYNK_AUTH_TOKEN "Blynk Token"


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>
#include <Blynk.h>


BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;

#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);//SCL-D1,SDA-D2--LCD0x3F
Servo myservo;  // create servo object to control a servo

char ssid[] = " "; // Enter Your Wifi Id
char pass[] = " "; // Enter Your Wifi Password

#define Buzzer D5

BLYNK_WRITE(V0)
{
      int s0 = param.asInt(); 
      if(s0==HIGH)  
      {
        digitalWrite(Buzzer,HIGH);
        delay(1000);
        digitalWrite(Buzzer,LOW);
        delay(100);
        myservo.write(0);
        delay(100);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pet Feeder");
        lcd.setCursor(0,1);
        lcd.print("Closed");
        
      }       
      else
      {
        digitalWrite(Buzzer,HIGH);
        delay(1000);
        digitalWrite(Buzzer,LOW);
        delay(100);
        myservo.write(180);
        delay(100);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pet Feeder");
        lcd.setCursor(0,1);
        lcd.print("Opened");
        
      }
      Blynk.virtualWrite(V0, s0);
}


void setup() 
{
    pinMode(Buzzer,OUTPUT);
    lcd.init();
    lcd.backlight();
    Project_Info();
    myservo.write(0);  // tell servo to go to position in variable 'pos'
    myservo.attach(D4);  // attaches the servo on GIO2 to the servo object
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Connecting");
    lcd.setCursor(0,1);
    lcd.print(ssid);
    delay(2500);
    Blynk.begin(auth, ssid, pass);//Splash screen delay
    delay(2000); 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(ssid);
    lcd.setCursor(0,1);
    lcd.print("Connected");
    delay(2500);
    digitalWrite(Buzzer,HIGH);
    delay(1000);
    digitalWrite(Buzzer,LOW);
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pet Feeder");
    lcd.setCursor(0,1);
    lcd.print("Closed");
}

void loop() 
{
   Blynk.run();
}

void Project_Info()
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("IOT Pet");
  lcd.setCursor(5,1);
  lcd.print("Feeder");
  delay(2500);
  
}
