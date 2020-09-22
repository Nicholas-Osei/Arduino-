
int druk = 2;
int aan = 0;
int led = 0;
int light=3;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(light, OUTPUT);
  pinMode(druk, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  led = digitalRead(light);
  aan = digitalRead(druk);
  if(aan==HIGH)
  {
    digitalWrite(light,HIGH);
  }
  else
  {
    digitalWrite(light,LOW);
  }
}
