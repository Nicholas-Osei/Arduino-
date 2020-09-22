
const int buttonPin = 3;
const int buttonPin2 = 2;
const int led = 4;
int buttonState = 0;
int buttonState1 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonPin2, INPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  noInterrupts();
  // critical, time-sensitive code here
  buttonState = digitalRead(buttonPin2);
  buttonState1 = digitalRead(buttonPin);
  interrupts();
  // other code here
  if (buttonState == HIGH) 
  {
    // turn LED on:
    digitalWrite(led, HIGH);
  } 
  if (buttonState1 == HIGH) 
  {
    // turn LED off:
    digitalWrite(led, LOW);
  }
}
