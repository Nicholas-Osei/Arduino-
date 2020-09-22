int pin = 2;
int led = 13;
bool aan;
bool VorigeStand;

void setup() {
  // put your setup code here, to run once:
    pinMode(pin,INPUT);
    pinMode(led, OUTPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:   
  aan = digitalRead(pin);  
  if(aan)
  {
    delay(200);
    VorigeStand = !VorigeStand;
    if(VorigeStand)
    {
      digitalWrite(led,HIGH);
    }
    else 
    {
      digitalWrite(led,LOW);
    }
  }
    



 
  
}
