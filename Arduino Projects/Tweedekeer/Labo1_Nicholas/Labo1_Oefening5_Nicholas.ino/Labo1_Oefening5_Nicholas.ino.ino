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

  int check = analogRead(sw);
  Serial.println(check);
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(check);
    digitalWrite(led[i], LOW);
  }
  for (int i = 5; i > 0; i--)
  {

    digitalWrite(led[i], HIGH);
    delay(check);
    digitalWrite(led[i], LOW);
    //delay(wait);

  }



}
