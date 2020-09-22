#include <Servo.h>
Servo mijnservo;
int potpin = 0;
int val;
void setup()
{
  mijnservo.attach(9);
}
void loop()
{
  val = analogRead(potpin);        
  val = map(val, 0, 1023, 0, 179);                  
  mijnservo.write(val);    
  delay(15);  
}
