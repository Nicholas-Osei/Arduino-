#include <Servo.h>
int servoPin = 4, val = 0, potPin = A0, MapVal = 0;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);
  myservo.write(val);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potPin);
  MapVal = map(val, 0, 1023, 0, 180);

  myservo.write(MapVal);
  delay(15);

}
