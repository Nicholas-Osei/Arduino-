//Anode leds
int anodeLeds[] = {4, 5, 6, 7, 8,9,10};

//Cathode digits
int cathodeDigits[] = {1, 11, 12, 13};

int eerstedigit, laatstedigit = 0;

void setup() {
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
  for (int i = eerstedigit; i < laatstedigit; i++) {
    digitalWrite(cathodeDigits[i], LOW);

    for (int p = 0; p < 7; p++) 
    {
      digitalWrite(anodeLeds[p], HIGH);
      delay(200);
    }
    for (int a = 0; a < 7; a++) 
    {
      digitalWrite(anodeLeds[a], LOW);
      delay(200);
    }
    for (int j = eerstedigit; j < laatstedigit; j++) 
    {
      digitalWrite(cathodeDigits[j], HIGH);
    }
  }
  if (laatstedigit < 4) 
  {
    laatstedigit++;
    eerstedigit++;
  }
  else 
  {
    laatstedigit = 1;
    eerstedigit = 0;
  }
}
