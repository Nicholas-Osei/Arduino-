int RoodLed = A0, GroenLed = A1, GeelLed = A2;

void setup() {
  // put your setup code here, to run once:
  pinMode(RoodLed, OUTPUT);
  pinMode(GroenLed, OUTPUT);
  pinMode(GeelLed, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    String lees = Serial.readStringUntil('\n');
    int ledValue = lees.toInt();
    Serial.println(ledValue);
    switch (ledValue)
    {
      case 0:
        digitalWrite(RoodLed, LOW);
        break;
      case 1:
        digitalWrite(RoodLed, HIGH);
        break;
      case 2:
        digitalWrite(GroenLed, LOW);
        break;
      case 3:
        digitalWrite(GroenLed, HIGH);
        break;
      case 4:
        digitalWrite(GeelLed, LOW);
        break;
      case 5:
        digitalWrite(GeelLed, HIGH);
        break;
    }

  }

}
