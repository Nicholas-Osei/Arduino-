int Led= 9, pot = A0,val;
void setup() {
  pinMode(pot, INPUT);
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    int value = Serial.read();
    analogWrite(Led, value);
  }
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255);
  Serial.write((int)val);
  delay(100);
}
