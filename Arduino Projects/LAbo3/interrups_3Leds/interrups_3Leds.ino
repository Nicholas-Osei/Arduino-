
const int buttonPin = 3;
const int buttonPin2 = 2;
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;

int buttonState = 0;
int buttonState1 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
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
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led3, HIGH);
    delay(1000);
  } 
  if (buttonState1 == HIGH) 
  {
    // turn LED off:
    digitalWrite(led1, LOW);
    delay(1000);
    digitalWrite(led2, LOW);
    delay(1000);
    digitalWrite(led3, LOW);
    delay(1000);
  }
}
