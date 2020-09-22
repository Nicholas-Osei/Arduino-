int anodeLeds[] = {4, 5, 6, 7, 8, 9, 10};
int cathodeDigits[] = {1, 11, 12, 13};
int displayBuf[2];

int i = 0, j = 0;
int startTime = 0;
int endTime;
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
  { 1, 1, 1, 0, 0, 1, 1 }
};   // 9
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

}

void loop() {
  // put your main code here, to run repeatedly:
  refreshDisplay(displayBuf[1], displayBuf[0]);
  // delay(1000);
  endTime = millis();                  // increments the counter approximately once a second
  if ((endTime - startTime) >= 1000)
  {
    if (++i > 9)
    {
      i = 0;
      if (++j > 9) j = 0;
    }
    displayBuf[0] = i;                // send the updated count to the display buffer
    displayBuf[1] = j;
    startTime = endTime;
  }


}
void displayDigit(int digit)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(anodeLeds[i], num_array[digit][i]);
  }
}
void refreshDisplay(int digit1, int digit0)
{
  digitalWrite(cathodeDigits[0], HIGH);  // displays digit 0 (least significant)
  digitalWrite(cathodeDigits[1], HIGH );
  digitalWrite(cathodeDigits[2], LOW );
  digitalWrite(cathodeDigits[3], HIGH );
  displayDigit(digit0);
  delay(5);
  digitalWrite(cathodeDigits[0], HIGH);   // then displays digit 1
  digitalWrite(cathodeDigits[1], LOW);
  digitalWrite(cathodeDigits[2], HIGH );
  digitalWrite(cathodeDigits[3], HIGH );
  displayDigit(digit1);
  delay(5);
}
