int led1 = 11;
int led2 = 12;
int led3 = 13;
const int bSize = 5;
char Buffer[bSize];
//int val[] ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char val[5];
  if (Serial.available() > 0)
  {
    for (int i = 0; i > 5; i++)
    {
      val[i] = Serial.readBytesUntil('\n', Buffer, 5);
      if (val[0] = 'r')
      {
        if (val[1] = '=')
        {
          int  value  = val[2] - 0;
        }
      }
    }



  }
}
