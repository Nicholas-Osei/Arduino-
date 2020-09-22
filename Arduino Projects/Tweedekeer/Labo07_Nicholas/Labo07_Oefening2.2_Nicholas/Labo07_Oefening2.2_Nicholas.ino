#include <NewPing.h>

const int echoPin = 2;
const int trigPin = 3;
const int Max_Afstand = 400;
int iterations = 5;
float Afstand;
long duration;

NewPing sonar(trigPin, echoPin, Max_Afstand);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  duration = sonar.ping_median(iterations);

  Afstand = (duration / 2) * 0.0343;

  Serial.print("Distance = ");
  if (Afstand >= 400 || Afstand <= 2)
  {
    Serial.println("Out of range");
  }
  else {
    Serial.print(Afstand);
    Serial.println(" cm");
    delay(400);
  }
  delay(400);





}
