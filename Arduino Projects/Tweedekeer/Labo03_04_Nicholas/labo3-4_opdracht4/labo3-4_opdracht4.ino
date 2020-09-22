int led[] = {A0, A1, A2, A3, A4, A5};
int sw1 = 2, sw2 = 3;
volatile bool aan = false;
int buttonPressed;
long randNumber = 6;
int Veranderen;
int pressed = 0;

int aantalKeerGeraakt;

void setup() {
  // put your setup code here, to run once:
  for (int i; i < 6; i++)
  {
    pinMode(led[i], OUTPUT);
  }
  Veranderen = sw1;
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sw1), ISRhit, FALLING);
  attachInterrupt(digitalPinToInterrupt(sw2), ISReindespel, FALLING);
  Serial.begin(9600);
  randomSeed(analogRead(6));
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonPressed = 1;
  if (buttonPressed == 1)
  {
    delay(50);
    buttonPressed = digitalRead(Veranderen);
    if (buttonPressed == 0)
    {
      if (aan)
      {
        pressed++;
        Veranderen = sw2;
        //randNumber = random(1, 6);
        randNumber = random(6);
        Serial.println(randNumber);
        if (digitalRead(led[randNumber]) == HIGH)
        {
          Serial.println("Fout gemikt");
          while (aan)
          {
            for (int i = 0; i < 6; i++)
            {
              digitalWrite(led[i], LOW);
            }
            int randNumberKnipperen = random(6);
            digitalWrite(led[randNumberKnipperen], HIGH);
            delay(1000);
            if ( pressed>=2  && digitalRead(led[randNumberKnipperen] == HIGH))
            {
              aantalKeerGeraakt++;
              Serial.println("Raak!");
              // Serial.println("Geraakt in " + aantalKeerGeraakt;  + " pogingen");
              Serial.print("Geraakt in ");
              Serial.print(aantalKeerGeraakt);
              Serial.println(" pogingen");
              aantalKeerGeraakt=0;
              //yeah = 0;
              aan = false;
            }
            else
            {
              pressed=0;
            }
            digitalWrite(led[randNumberKnipperen], LOW);
            delay(1000);
          }
        }
       
      }
      else
      {
        Veranderen = sw1;
        pressed = 0;
        if (randNumber == 6)
        {
          Serial.println("Spel onderbroken - opnieuw gestart");
          for (int i = 0; i < 6; i++)
          {
            digitalWrite(led[i], LOW);
          }
        }
        else
        {
          Serial.println(randNumber);
          delay(50);
          digitalWrite(led[randNumber], HIGH);

          randNumber = random(6);
          Serial.println(randNumber);
          delay(50);
          digitalWrite(led[randNumber], HIGH);

          randNumber = random(6);
          Serial.println(randNumber);
          delay(50);
          digitalWrite(led[randNumber], HIGH);
          randNumber = 6;
        }
      }
    }
  }
}



void ISRhit()
{
  Veranderen = sw1;
  aan = true;
}
void ISReindespel()
{
  Veranderen = sw2;
  aan = false;
}
