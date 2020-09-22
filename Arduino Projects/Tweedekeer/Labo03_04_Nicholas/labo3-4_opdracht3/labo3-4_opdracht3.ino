int sw2 = 2, sw3 = 3;
volatile boolean aan =  false;
int aantalLeds = 0, Leds = 0, Veranderen;
int buttonPressed = 0, off = 0;
int led[] = {4, 5, 6};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++)
  {
    pinMode(led[i], OUTPUT);
  }
  Veranderen = sw2;
  attachInterrupt(digitalPinToInterrupt(sw2), ISROn, RISING);
  attachInterrupt(digitalPinToInterrupt(sw3), ISROff, RISING);
  Serial.begin(9600);
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
        aan = false;
        Veranderen = sw3;
        aantalLeds++;
        if (aantalLeds > 3)
        {
          aantalLeds = 3;
        }
        
      }
      else
      {
        aan = true;
        Veranderen = sw2;
        off++;
        if (off > 3)
        {
          off = 0;
        }
      }
    }
    for (int i = 0; i < aantalLeds; i++)
    {
      digitalWrite(led[i], HIGH);
    }
    for (int i = 0; i < off; i++)
    {
      digitalWrite(led[i], LOW);
    }
  }
}
//  void Debouncing(int sw)
//  {
//
//    //  buttonPressed = digitalRead(sw);
//    if (buttonPressed == 1)
//    {
//      delay(50);
//      buttonPressed = digitalRead(sw);
//      if (buttonPressed == 0)
//      {
//        if (aan)
//        {
//          aantalLeds++;
//          if (aantalLeds > 3)
//          {
//            aantalLeds = 3;
//          }
//        }
//        else
//        {
//          //aantalLeds--;
//          off++;
//          if (off > 3)
//          {
//            off = 0;
//          }
//        }
//      }
//
//    }


void ISROn()
{
  Veranderen = sw2;
  aan = true;
}
void ISROff()
{
  Veranderen = sw3;
  aan = false;
}

//int sw1 = 2;
//int sw2 = 3;
//bool state;
//int leds[] = {4, 5, 6};
//int AantalLeds = 0;
//void setup() {
//  // put your setup code here, to run once:
//  //  pinMode(sw1,INPUT);
//  //  pinMode(sw2,INPUT);
//  
//  for (int i = 0; i < 3; i++)
//  {
//    pinMode(leds[i], OUTPUT);
//  }
//
//  attachInterrupt(digitalPinToInterrupt(sw1), Aan, RISING);
//  attachInterrupt(digitalPinToInterrupt(sw2), Uit, RISING);
//  Serial.begin(9600);
//
//
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  for (int i = 0; i < AantalLeds; i++)
//  {
//    digitalWrite(leds[i], LOW);
//  }
//  int lol = digitalRead(sw2);
//  int pff = digitalRead(sw1);
//  if (state && pff == HIGH)
//  {
//    delay(500);
//    AantalLeds++;
//    state = false;
//
//  }
//  if (state == false && lol == HIGH)
//  {
//    delay(500);
//    AantalLeds--;
//    state = true;
//  }
//  Serial.println(AantalLeds);
//
//  for (int i = 0; i < AantalLeds; i++)
//  {
//    digitalWrite(leds[i], HIGH);
//  }
//  delay(50);
//
//
//}
//void Aan()
//{
//  state = true;
//}
//void Uit()
//{
//  state = false;
//}
