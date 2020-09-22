int pinA = 2;
int pinB = 4;

int Leds[] = {5, 6, 7, 8, 9, 10, 12}; //leds

int Previous,State;
int counter=0;
int rot_dir = 0;




void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

  for (int i = 0 ; i < 6 ; i++)
  {
    pinMode(Leds[i], OUTPUT);
  }

  digitalWrite (pinA, HIGH);   // enable pull-up
  digitalWrite (pinB, HIGH);   // enable pull-up

  Serial.begin(9600);

  attachInterrupt (digitalPinToInterrupt(pinA), rotaryTurn, FALLING);    // interrupt 0 is pin 2, For rotary encoder
}


void loop() {
  State = digitalRead(pinA);
  if (State != Previous)
  {
    for (int i = 0 ; i < 6 ; i++)
    {
      digitalWrite(Leds[i], LOW);
    }
    if (rot_dir != State)
    {
      delay(500);
      counter++;
      if (counter > 8)
      {
        counter = 8;
      }
      
    }
    else
    {
      delay(500);
      counter--;
      if (counter < 0)
      {
        counter = 0;
      }
    }
    Serial.print("Position: ");
    Serial.println(counter);
    for (int i = 0 ; i < counter ; i++)
    {
      digitalWrite(Leds[i], HIGH);
    }
    Previous = State;
  }

}
void rotaryTurn()
{
  rot_dir = digitalRead(pinB);
  State = 1;
}
