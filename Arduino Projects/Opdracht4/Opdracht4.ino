int analogPin = A0;
int led1 = 4;
int led2= 5;
int waarde = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(analogPin,INPUT);
  digitalWrite(analogPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  waarde = analogRead(analogPin);
  Serial.print ("\r\nGeef een getal tussen 0 tot 1023: ");
    //waiting for input
    while (Serial.available() == 0);
    int val = Serial.parseInt(); 
    Serial.println(val);
    if(waarde < val)
    {
      digitalWrite(led1,HIGH);
    }
    else
    {
      digitalWrite(led2,HIGH);
    }

}
