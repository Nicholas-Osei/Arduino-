bool aan;
int Switch = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(Switch,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
      aan = digitalRead(Switch);
      if(aan)
      {
        digitalWrite(LED_BUILTIN,HIGH);
      }
      else
      {
        digitalWrite(LED_BUILTIN,LOW);
      }
}
