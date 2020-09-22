#define ROTA 2
#define ROTB 4
int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;
int led6 = 10;
int led7 = 11;
int led8 = 12;
long beginstaat = 0;
long eindstaat = 0;
long upperLimit = 7;
long DownLimit = 1;




void setup() {
  pinMode(ROTA, INPUT);
  pinMode(ROTB, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

  digitalWrite (ROTA, HIGH);   // enable pull-up
  digitalWrite (ROTB, HIGH);   // enable pull-up

  Serial.begin(9600);

  attachInterrupt (0, rotaryTurn, RISING);    // interrupt 0 is pin 2, For rotary encoder
}


void loop() {
  if (eindstaat != beginstaat) {
    Serial.println(beginstaat);
    if (beginstaat > upperLimit)
    {
      beginstaat = upperLimit;
    }
    else if (beginstaat == 1)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
    else if (beginstaat == 2)
    {
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }
    else if (beginstaat == 3)
    {
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    }
    else if (beginstaat == 4)
    {
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
    }
    else if (beginstaat == 5)
    {
      digitalWrite(led5, HIGH);
      digitalWrite(led6, LOW);
    }
    else if (beginstaat == 6)
    {
      digitalWrite(led6, HIGH);
      digitalWrite(led7, LOW);
    }
    else if (beginstaat == 8)
    {
      digitalWrite(led8, HIGH);
    }
    else if (beginstaat == 0)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
    }
    else if (beginstaat < DownLimit)
    {
      beginstaat = DownLimit;
    }
    eindstaat = beginstaat;
  }
}
void rotaryTurn()
{
  if (digitalRead (ROTB)) {
    beginstaat++;
  }
  else
    beginstaat--;
}
