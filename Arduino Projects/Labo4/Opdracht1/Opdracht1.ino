int pin1 = 2;
int pin2 = 5;
int aantal=0;
long beginstaat = 0;
long eindstaat = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  Serial.begin(9600);
  eindstaat = digitalRead(pin2); 
}

void loop() {
  // put your main code here, to run repeatedly:
  beginstaat=digitalRead(pin2);

   if(beginstaat != eindstaat)
   {
      if (digitalRead(pin1) != beginstaat) 
      { 
       aantal++;
      }
      else
      {
        aantal--;
      }
      Serial.print("Positie: ");
      Serial.println(aantal);
   }
  eindstaat = beginstaat;

}
