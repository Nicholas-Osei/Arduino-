int anodeLeds[] = {4, 5, 6, 7, 8, 9, 10};
int cathodeDigits[] = {1, 11, 12, 13};
int displayBuf[4];
int i=0,j = 0,p=0;
int startTime = 0;
int endTime;
int pinA = 2;
int pinB = 3;
int Previous, State;
int counter = 0;
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
  displayBuf[1] = 0;    // initializes the display
  displayBuf[0] = 0;
  displayBuf[2] = 0;    
  displayBuf[3] = 0;
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  digitalWrite (pinA, HIGH);   // enable pull-up
  digitalWrite (pinB, HIGH);   // enable pull-up
  attachInterrupt (digitalPinToInterrupt(pinA), rotaryTurn, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  refreshDisplay(displayBuf[3],displayBuf[2],displayBuf[1], displayBuf[0]); //Brandt leds
  State = digitalRead(pinA);
  if (State != Previous)
  {
    if (digitalRead(pinB) != State)
    {
      counter++;
    }
    else
    {
      counter--;
    }
//    Serial.print("Position: ");
//    Serial.println(counter);
    Previous = State;
  }
  if (counter > 9)
  {
    j++;
    counter = 0;
    if (j > 9) 
    {
      j = 0;
      i++;
       if (i > 9) 
      {
        i=0;
        p++;
      }
    }
  }
  if (counter < 0 && j > 0)
  {
    j--;
    counter = 9; //terug op 9 zetten
  }
  if (j < 0 && i > 0)
  {
    i--;
    j = 9; //terug op 9 zetten
  }
  if (i < 0 && p > 0)
  {
    p--;
    i = 9; //terug op 9 zetten
  }
  displayBuf[0] = i; 
  displayBuf[1]=p;   
  displayBuf[2] = j;
  displayBuf[3] = counter; // send the updated count to the display buffer

}
void displayDigit(int digit)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(anodeLeds[i], num_array[digit][i]);
  }
}
void refreshDisplay(int digit3,int digit2,int digit1, int digit0)
{
  digitalWrite(cathodeDigits[0], HIGH);  // toont segment D
  digitalWrite(cathodeDigits[1], HIGH );
  digitalWrite(cathodeDigits[2], LOW );
  digitalWrite(cathodeDigits[3], HIGH );
  displayDigit(digit0);
  delay(5);
  digitalWrite(cathodeDigits[0], HIGH);   // toont segment c
  digitalWrite(cathodeDigits[1], LOW);
  digitalWrite(cathodeDigits[2], HIGH );
  digitalWrite(cathodeDigits[3], HIGH );
  displayDigit(digit1);
  delay(5);
  digitalWrite(cathodeDigits[0], HIGH);   // toont segment B
  digitalWrite(cathodeDigits[1], HIGH);
  digitalWrite(cathodeDigits[2], HIGH );
  digitalWrite(cathodeDigits[3], LOW );
  displayDigit(digit2);
  delay(5);
  digitalWrite(cathodeDigits[0], LOW);   // toont segment A
  digitalWrite(cathodeDigits[1], HIGH);
  digitalWrite(cathodeDigits[2], HIGH );
  digitalWrite(cathodeDigits[3], HIGH );
  displayDigit(digit3);
  delay(5);
}
void rotaryTurn()
{
  rot_dir = digitalRead(pinA);
  State = 1;
}
