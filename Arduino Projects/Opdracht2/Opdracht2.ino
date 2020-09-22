#include <EEPROM.h>
int ledPin = 3;
int buttonPin = 2;
int lastButtonState = 1;
int lastPress;
int debounceTime = 20;
int teller;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  teller = EEPROM.read(0);
  EEPROM.write(0,0);
}

void loop() {  
  int buttonState = digitalRead(buttonPin);
  
  if((millis() - lastPress) > debounceTime)   
  {
    lastPress = millis();                                                     
    if(buttonState == 0 && lastButtonState == 1)    
    {
      teller++;
      EEPROM.write(0, teller); 
      digitalWrite(ledPin, HIGH); 
      lastButtonState = 0;    
      Serial.print("Teller is nu op : ");
      Serial.println(teller);
    }
    if(buttonState == 1 && lastButtonState == 0)    
    {
      lastButtonState = 1;   
      digitalWrite(ledPin, LOW); 
    }
  }
}
