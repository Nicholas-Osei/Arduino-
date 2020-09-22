int analogPin = A3;
double val = 0;
String Plusteken="+";
void setup() {
  // put your setup code here, to run once:
  pinMode(analogPin,INPUT);
  digitalWrite(analogPin, HIGH);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin)* (5.0/1024.0) ;  
  Plustekenen(val);

}
void Plustekenen(int aantal)
{
  Serial.print("0");
  aantal*=10;
  for(int i=1;i<=aantal;i++)
  { 
      Serial.print(Plusteken);   
  }
  Serial.println(" ");
}


//int check=analogRead(sw);
//  check = map(check,0,1023,0,5);
//  Serial.print("0");
//  check*=10;
//  for(int i=0;i<check;i++)
//  {
//    Serial.println(plus);
//  }
//  Serial.println("");
