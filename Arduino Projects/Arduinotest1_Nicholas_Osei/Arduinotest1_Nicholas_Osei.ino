#include <EEPROM.h>

int A = 2;
int B = 3;
int Leds[] = {4, 5, 6};
int val, state, previous;
long tijd, debounce = 200;
int trein = 0;
bool aan;
int startTime = 0;
int endTime;

String vraag;

int address = 0;
void setup() {
  // put your setup code here, to run once:
  for (int i=0; i < 3; i++)
  {
    pinMode(Leds[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(A), Sensor1, RISING);
  attachInterrupt(digitalPinToInterrupt(B), Sensor2, RISING);

  trein = EEPROM.read(address);
  EEPROM.write(address, trein);
  Serial.begin(9600);
  Serial.print("Trein waarde ");
  Serial.println(trein);

  Serial.print("Wil je je het aantal keren dat de trein is gepasseerd wissen j/n ");


}

void loop() {
  // put your main code here, to run repeatedly:
  GroeneLed();
  endTime = millis();

  if (Serial.available() > 0)
  {
    vraag  = Serial.readStringUntil("/n");
    if (vraag == "j")
    {
      EEPROM.write(0, 0);
    }
    else
    {
      Serial.println("ok");
    }
  }
  if (aan == true && digitalRead(A) == HIGH)
  {

    if ((endTime - startTime) >= 5000)
    {
      Serial.println("Trein komt aan");
      trein++;
      EEPROM.write(address, trein);
      startTime = endTime;
    }
    val = digitalRead(A);
    Debounce();
    RodeLed();
    digitalWrite(Leds[0], LOW);
    aan = false;
    digitalRead(A) == LOW;


  }
  else if (aan == false  && digitalRead(B) == HIGH)
  {
    val = digitalRead(B);
    Debounce(); 
    GroeneLed();
    digitalWrite(Leds[1], HIGH);
    digitalWrite(Leds[2], HIGH);
    aan = true;
    digitalRead(B) == LOW;

  }


}

void Sensor1()
{
  aan = true;
}
void Sensor2()
{
  aan =  false;
}
void Debounce()
{
  if (val == LOW && previous == HIGH)
  {
    if ((debounce - millis() ) > tijd)
    {
      tijd = debounce ;
    }
  }
  previous = val;
}
void GroeneLed()
{
  digitalWrite(Leds[0], HIGH);
  delay(1000);
  digitalWrite(Leds[0], LOW);
  delay(1000);
}
void RodeLed()
{
  digitalWrite(Leds[1], HIGH);
  delay(1000);
  digitalWrite(Leds[1], LOW);
  delay(1000);
  digitalWrite(Leds[2], HIGH);
  delay(1000);
  digitalWrite(Leds[2], LOW);
  delay(1000);

}
