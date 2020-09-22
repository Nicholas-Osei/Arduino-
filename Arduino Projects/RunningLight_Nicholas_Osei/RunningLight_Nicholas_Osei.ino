int ledPin[]={2,3,4,5,6};
int analogPin = A3;
int aantal=0;

void setup()
{
  pinMode(aantal,INPUT);
  digitalWrite(analogPin, HIGH);
  Serial.begin(9600);
  
  for (int i =0; i <5; i++)
  {
    pinMode(ledPin[i],OUTPUT);
  }
}

void loop()
{
  aantal = analogRead(analogPin);
  Serial.println(aantal);
  for(int i =0; i<5; i++)
  {
    digitalWrite(ledPin[i],HIGH);
    delay(aantal);
    digitalWrite(ledPin[i],LOW);
  }

  for(int i =4; i>=0; i--)
  {
    digitalWrite(ledPin[i],HIGH);
    delay(aantal);
    digitalWrite(ledPin[i],LOW);
  }
}
