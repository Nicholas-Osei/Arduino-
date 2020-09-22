int pinA = 2;
int pinB = 3;

//Anode leds
int anodeLeds[] = {3, 5, 6, 7, 8, 9, 10};

//Cathode digits
int cathodeDigits[] = {1, 11, 12, 13};

int eerstedigit, laatstedigit = 0;

int Previous, State;
int counter = 0;
int rot_dir = 0;

void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

  digitalWrite (pinA, HIGH);   // enable pull-up
  digitalWrite (pinB, HIGH);   // enable pull-up

  attachInterrupt (digitalPinToInterrupt(pinA), rotaryTurn, FALLING);

  for (int i = 0; i < 7; i++) {
    pinMode(anodeLeds[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(cathodeDigits[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(cathodeDigits[i], HIGH);
  }
}

void loop() {

  State = digitalRead(pinA);
  if (State != Previous)
  {
    if (digitalRead(pinB) != State)
    {
      counter++;
      if (counter > 8)
      {
        counter = 8;
      }
      delay(200);
    }
    else
    {
      counter--;
      if (counter < 8)
      {
        counter = 0;
      }
      delay(200);
    }
    switch (counter)
    {
      case 0:
        for (int i = 0; i < 6; i++) {
          digitalWrite(anodeLeds[i], HIGH);
        }
        digitalWrite(anodeLeds[7], LOW);
        break;
      case 1:
        digitalWrite(anodeLeds[0], LOW);
        digitalWrite(anodeLeds[1], HIGH);
        digitalWrite(anodeLeds[2], HIGH);
        for (int i = 3; i < 7; i++) {
          digitalWrite(anodeLeds[i], LOW);
        }
        break;
      case 2:
        digitalWrite(anodeLeds[0], HIGH);
        digitalWrite(anodeLeds[1], HIGH);
        digitalWrite(anodeLeds[2], LOW);
        digitalWrite(anodeLeds[3], HIGH);
        digitalWrite(anodeLeds[4], HIGH);
        digitalWrite(anodeLeds[5], LOW);
        digitalWrite(anodeLeds[6], HIGH);
        break;
      case 3:
        for (int i = 0; i < 3; i++) {
          digitalWrite(anodeLeds[i], HIGH);
        }
        digitalWrite(anodeLeds[4], LOW);
        digitalWrite(anodeLeds[5], LOW);
        digitalWrite(anodeLeds[6], HIGH);
        break;
      case 4:
        digitalWrite(anodeLeds[0], LOW);
        digitalWrite(anodeLeds[1], HIGH);
        digitalWrite(anodeLeds[2], HIGH);
        digitalWrite(anodeLeds[3], LOW);
        digitalWrite(anodeLeds[4], LOW);
        digitalWrite(anodeLeds[5], HIGH);
        digitalWrite(anodeLeds[6], HIGH);
        break;
      case 5:
        digitalWrite(anodeLeds[0], HIGH);
        digitalWrite(anodeLeds[1], LOW);
        digitalWrite(anodeLeds[2], HIGH);
        digitalWrite(anodeLeds[3], HIGH);
        digitalWrite(anodeLeds[4], LOW);
        digitalWrite(anodeLeds[5], HIGH);
        digitalWrite(anodeLeds[6], HIGH);
        break;
      case 6:
        digitalWrite(anodeLeds[0], HIGH);
        digitalWrite(anodeLeds[1], LOW);
        digitalWrite(anodeLeds[2], HIGH);
        digitalWrite(anodeLeds[3], HIGH);
        digitalWrite(anodeLeds[4], HIGH);
        digitalWrite(anodeLeds[5], HIGH);
        digitalWrite(anodeLeds[6], HIGH);

        break;
      case 7:
        digitalWrite(anodeLeds[0], HIGH);
        digitalWrite(anodeLeds[1], HIGH);
        digitalWrite(anodeLeds[2], HIGH);
        digitalWrite(anodeLeds[3], LOW);
        digitalWrite(anodeLeds[4], LOW);
        digitalWrite(anodeLeds[5], LOW);
        digitalWrite(anodeLeds[6], LOW);
        break;
      case 8:
        for (int i = 0; i < 6; i++) {
          digitalWrite(anodeLeds[i], HIGH);
        }
        break;
      case 9:
        digitalWrite(anodeLeds[0], HIGH);
        digitalWrite(anodeLeds[1], HIGH);
        digitalWrite(anodeLeds[2], HIGH);
        digitalWrite(anodeLeds[3], HIGH);
        digitalWrite(anodeLeds[4], LOW);
        digitalWrite(anodeLeds[5], HIGH);
        digitalWrite(anodeLeds[6], HIGH);
        break;
        //
    }
    if (laatstedigit < 4) {
      laatstedigit++;
      eerstedigit++;
    }
    else {
      laatstedigit = 1;
      eerstedigit = 0;
    }
  }
}
void rotaryTurn()
{
  rot_dir = digitalRead(pinA);
  State = 1;
}
