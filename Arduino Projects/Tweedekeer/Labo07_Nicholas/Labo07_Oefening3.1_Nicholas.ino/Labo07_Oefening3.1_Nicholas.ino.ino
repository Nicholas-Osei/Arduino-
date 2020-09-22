#include <Servo.h>
int servoPin = 4, Positie = 0;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);
  myservo.write(Positie);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 180; i++)
  {
    Positie = i;
    myservo.write(Positie);
    delay(15);
  }
  for (int i = 180; i >= 0; i--)
  {
    Positie = i;
    myservo.write(Positie);
    delay(15);
  }
}
