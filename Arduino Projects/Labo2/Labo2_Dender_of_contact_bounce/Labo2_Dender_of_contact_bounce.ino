
int druk = 2;
int light=A0;
bool toggle =false;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(light, OUTPUT);
  pinMode(druk, INPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
//  led = digitalRead(light);
    bool aan = digitalRead(druk);
 
  if(aan)
  {
   
    delay(20);
     Serial.println("looool");
    toggle = !toggle;
    if(toggle)
    {
      digitalWrite(light,HIGH);
    }
    else
    {
       digitalWrite(light,LOW);
    }
    while (digitalRead(druk)) {}
    delay(20);
  }

}
  
  
