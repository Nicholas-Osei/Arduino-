
int druk = 10;
int aan = 0;
int led = 0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(druk, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  aan = digitalRead(druk);
  if(aan==HIGH)
  {
    digitalWrite(LED_BUILTIN,HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN,LOW);
  }
}
