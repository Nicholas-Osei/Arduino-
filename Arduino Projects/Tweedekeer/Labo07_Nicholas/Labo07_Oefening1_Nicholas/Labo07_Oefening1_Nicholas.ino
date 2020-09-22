const int echoPin = 2;
const int trigPin = 3;

long duration;
float distance;
void setup() {
  // put your setup code here, to run once:
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
  //distance = ( duration / 29 ) / 2;
  distance = (duration / 2) * 0.0343;

  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2)
  {
    Serial.println(" Out of range");
  }
  else
  {
    Serial.print(distance);
    Serial.println("cm");
    delay(400);
  }
  delay(400);


}
