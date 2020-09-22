
const float pinTrig= 2;
const float pinEcho=3;
float duur;
int afstand;

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
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig,LOW);

  duur = pulseIn(pinEcho,HIGH);

  afstand = duur*0.034/2;
  if(afstand <2 || afstand > 400 )
  {
    Serial.print("ERROR  ");
    Serial.print("Afstand is:  ");
    Serial.print(afstand);
    Serial.print("cm");
    Serial.print(". Dit is kleiner dan 2 of groter dan 400");
    Serial.println("cm");
  }
  else 
  {
    Serial.print("Afstand: ");
    Serial.print(afstand);
    Serial.println("cm");
  }
  

  

  
  
  

}
