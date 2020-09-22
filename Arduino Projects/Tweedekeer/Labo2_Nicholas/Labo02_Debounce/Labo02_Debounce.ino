int pin = 2;
int led = 3;
bool aan;
int State_Led =HIGH,StateButton,PreviousStateButton = LOW;
unsigned long VorigeDebounceTime = 0; 
unsigned long debounceDelay = 50;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(pin,INPUT);
  digitalWrite(led,State_Led);

  
  

}

void loop() {
  // put your main code here, to run repeatedly:

  int leesSwitch = digitalRead(pin);

  if(leesSwitch != PreviousStateButton )
  {
    VorigeDebounceTime = millis();
  }
  if((millis()- VorigeDebounceTime) > debounceDelay)
  {
    if (leesSwitch != StateButton) {
      StateButton = leesSwitch;
      if (StateButton == HIGH) {
        State_Led= !State_Led;
      }
    }
  }
  digitalWrite(led, State_Led);
  PreviousStateButton = leesSwitch;

}

//Bron : https://www.arduino.cc/en/tutorial/debounce
