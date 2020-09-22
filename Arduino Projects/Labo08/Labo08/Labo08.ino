#include <SoftwareSerial.h>
SoftwareSerial portOne(0, 1);
const int buttonPin = 3;
const int buttonPin2 = 2;
int buttonState = 0;
int buttonState1 = 0;
int val = 0;
int led = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  portOne.begin(9600);
//  val = Serial.List();
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin2);
  if(Serial.available()>0)
  {
    val = Serial.read();
    delay(5);
    if (buttonState == HIGH) 
    {
      if(val == '1')
      {
        digitalWrite(led,HIGH);
        delay(5);
        val=0;
      }
    } 
    
    if (buttonState1 == HIGH) 
    {
      if(val == '2')
      {
        digitalWrite(led,HIGH);
        delay(100);
        val=0;
        
      }
      
    }
    else
    {
      buttonState1 == LOW;
    } 
    
  }
}
