int pinA = 2;
int pinB = 3;
int counter = 0;
int Previous, State;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  Serial.begin(9600);
  Previous = digitalRead(pinA);
}

void loop() {
  // put your main code here, to run repeatedly:
  State = digitalRead(pinA);
  if (State != Previous)
  {
    if (digitalRead(pinB) != State)
    {
      counter++;
      delay(500);
    }
    else
    {
      counter--;
      delay(500);
    }
    Serial.print("Position: ");
    Serial.println(counter);
    Previous = State;
  }



}
