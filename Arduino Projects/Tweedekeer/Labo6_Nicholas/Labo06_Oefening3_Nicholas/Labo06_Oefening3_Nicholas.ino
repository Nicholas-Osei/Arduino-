int AnodeLeds[]={2,3,4,5,6,7,8};
int SegmentDigit=9;
int displayBuf=0; // geeft aan welke cijfer op  het segment verschijnt 
int input=0;

int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9


void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<7;i++)
  {
    pinMode(AnodeLeds[i],OUTPUT);
  }
  pinMode(SegmentDigit,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  refreshDisplay(displayBuf);
  if(Serial.available() > 0)
  {
    input = Serial.parseInt();
    Serial.setTimeout(15000);
    Serial.println(input);
  }
  displayBuf=input;
  
}
void sevenWrite(int digit)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(AnodeLeds[i], num_array[digit][i]);
  }
}
void refreshDisplay(int digit1)//zet de  juist  segment aan  en stuur geeft de waarde weer
{
  digitalWrite(SegmentDigit, LOW);
  sevenWrite(digit1);
  
}
