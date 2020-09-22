#include <NewPing.h>
const float pinTrig= 2;
const float pinEcho=3;
float duur;
int afstand;
int afstandIn_cm;
int afstandmediaan;
int iterations;

NewPing sonar(pinTrig,pinEcho,afstand);







void setup() {
  // put your setup code here, to run once:
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(pinTrig,LOW);
  delayMicroseconds(2);
//sonar.ping_median(iterations);
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig,LOW);
  
  duur = pulseIn(pinEcho,HIGH);
  afstandIn_cm = sonar.ping_cm();
  
  afstand = duur*0.034/2;
  Serial.print("Ping: ");
  Serial.print(afstandIn_cm); 
  Serial.println(" cm");
  iterations = afstand;
  afstandmediaan=sonar.ping_median(iterations);
  Serial.print("Ping mediaan: ");
  Serial.println(afstandmediaan); 
  
  
  if(afstand <2 || afstand > 400 )
  {
    Serial.print("ERROR  ");
    Serial.print("Afstand is:  ");
    Serial.print(afstand);
    Serial.println(". Dit is kleiner dan 2 of groter dan 400");
    //Serial.println("cm");
  }
  else 
  {
    Serial.print("Afstand: ");
    Serial.print(afstand);
    Serial.println("cm");
    //Serial.println(afstandIn_cm);
    
    
  }
  

  

  
  
  

}
