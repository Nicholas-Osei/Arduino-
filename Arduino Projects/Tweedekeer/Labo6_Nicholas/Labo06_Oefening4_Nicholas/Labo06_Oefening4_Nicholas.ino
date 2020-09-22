int AnalogValue = 0;
int GroeneLed = 4;
int RodeLed = 5;
int userInput = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(GroeneLed, OUTPUT);
  pinMode(RodeLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Geef een getal in van  0 tot 1023");

}

void loop() {
  // put your main code here, to run repeatedly:
  AnalogValue = analogRead(0);
  Serial.println(AnalogValue);
  while (Serial.available() > 0)
  {
    
    userInput = Serial.parseInt();
    
    if (AnalogValue > userInput)
    {
      digitalWrite(GroeneLed, HIGH);
    }
    else
    {
      digitalWrite(RodeLed, HIGH);
    }
    Serial.setTimeout(15000);
    
  }



}
