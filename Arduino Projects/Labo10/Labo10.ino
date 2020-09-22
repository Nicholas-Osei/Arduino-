int ledRood = 13;
int ledGroen = 12;
int ledGeel = 11;
int lees = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(ledRood,OUTPUT);
  pinMode(ledGroen,OUTPUT);
  pinMode(ledGeel,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   
  if(Serial.available()>0)
  {
    lees = Serial.read(); // neemt wat je typt naar de seriele monitor
    Serial.println(lees);
    if(lees == '0')    
      {
           digitalWrite(ledRood, LOW);        
      }
    else if(lees == '1')
      {
         digitalWrite(ledRood, HIGH);
      }
     else if(lees == '2')
      {
         digitalWrite(ledGroen, LOW);
      }
     else if(lees == '3')
      {
         digitalWrite(ledGroen, HIGH);
      }
     else if(lees == '4')
      {
         digitalWrite(ledGeel, LOW);
      }
     else if(lees == '5')
      {
         digitalWrite(ledGeel, HIGH);
      }
  }
 

}
