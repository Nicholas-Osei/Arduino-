int anodeLeds[] = {4, 5, 6, 7, 8, 9, 10};
int cathodeDigits[] = {1, 11, 12, 13};

int pinA = 2;
int pinB = 3;
int Previous,State;
int counter=0;
int rot_dir = 0;


int num_array[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 0, 0, 1, 1 }};   // 9
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++)
  {
    pinMode(anodeLeds[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++)
  {
    pinMode(cathodeDigits[i], OUTPUT);
  }
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  digitalWrite (pinA, HIGH);   // enable pull-up
  digitalWrite (pinB, HIGH);   // enable pull-up
  attachInterrupt (digitalPinToInterrupt(pinA), rotaryTurn, FALLING);    // interrupt 0 is pin 2, For rotary encoder
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(cathodeDigits[0], HIGH);
  digitalWrite(cathodeDigits[1], HIGH);
  digitalWrite(cathodeDigits[2], LOW);
  digitalWrite(cathodeDigits[3], HIGH);
  //for (int n = 0; n < 10; n++)    // display digits 0 - 9 and decimal point
  //{
   
  //}

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
      if (counter < 0)
      {
        counter = 0;
      }
      delay(200);
    }
    Serial.print("Position: ");
    Serial.println(counter);
    displayDigit(counter);
    delay(1000);
    Previous = State;
  }

}
void rotaryTurn()
{
  rot_dir = digitalRead(pinA);
  State = 1;
}
void displayDigit(int digit)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(anodeLeds[i], num_array[digit][i]);
  }
}
