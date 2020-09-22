int led = 4;
int SW1 = 2;
int SW2 = 3;
bool aan,af;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  aan = digitalRead(SW1);
  af= digitalRead(SW2);

  if(aan)
  {
    digitalWrite(led,HIGH);
  }
  if(af)
  {
    digitalWrite(led,LOW);
  }

}
