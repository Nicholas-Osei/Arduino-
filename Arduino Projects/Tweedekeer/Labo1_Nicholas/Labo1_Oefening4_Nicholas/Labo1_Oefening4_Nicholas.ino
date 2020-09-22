int led[] = {2, 3, 4, 5, 6};
int sw = A0;
int wait = 1000;


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 5; i++)
  {
    pinMode(led[i], OUTPUT);
  }

  Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(led[i], LOW);
  }
  int check = analogRead(sw);
  check = map(check, 0, 1023, 0, 6);
  
  Serial.println(check);
  
  for (int i = 0; i < check; i++)
  {
    digitalWrite(led[i], HIGH);
  }
  delay(wait);



}
