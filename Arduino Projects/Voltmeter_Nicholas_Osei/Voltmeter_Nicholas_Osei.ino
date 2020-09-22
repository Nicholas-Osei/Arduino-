const int led1 = 2;
const int led2 = 3;
const int led3=4;
const int led4=5;
const int led5=6;
int analogPin = A3;
double val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(analogPin,INPUT);
  digitalWrite(analogPin, HIGH);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin)* (5.0/1024.0) ;
  Serial.println(val);
  if (val >= 0 && val < 1) 
  {
      // turn LED on:
    digitalWrite(led1, HIGH);
  }
  else if (val >= 1 && val < 2) 
  {
    // turn LED on:
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    
  }
  else if (val >= 2 && val < 3) 
  {
    // turn LED on:
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if (val >= 3 && val < 4) 
  {
    // turn LED on:
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    
  }
  else if (val > 4 ) 
  {
    // turn LED on:
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
   }

}
