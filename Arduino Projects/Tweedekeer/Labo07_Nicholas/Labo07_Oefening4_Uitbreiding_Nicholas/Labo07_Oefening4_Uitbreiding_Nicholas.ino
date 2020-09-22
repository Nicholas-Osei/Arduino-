#include <Stepper.h>
#include <Servo.h>

const int trigPin = 3, echoPin = 2;
float distance, duration;
int MapVal;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(4);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  MapVal = map(distance, 0, 400, 0, 135);
  if (MapVal < 20)
  {
    myservo.write(135);
  }
  else
  {
    myservo.write(45);
  }
  delay(500);

}
