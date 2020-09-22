int led=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  attachInterrupt(0,TurnLedOn,FALLING);
  attachInterrupt(1,TurnLedOff,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void TurnLedOn()
{
    digitalWrite(led,HIGH);
}
void TurnLedOff()
{
    digitalWrite(led,LOW);
}
