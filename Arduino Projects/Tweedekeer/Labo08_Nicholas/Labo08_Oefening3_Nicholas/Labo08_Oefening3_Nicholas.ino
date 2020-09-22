int Switch = 2;
bool Pressed;

//char addres[] = {0x0100,0x0110,0x0120};
char *memory ;

int locatie=20;


void setup() {
  // put your setup code here, to run once:
  pinMode(Switch, INPUT);
  Serial.begin(9600);
  memory = (char *)  0x0100;
  for (int i = 1; i < 20; i++)
  {
    Serial.print(" 0x0");
    if (i % 16 == 0)
    {

      Serial.print((int)memory, HEX);
      Serial.println();
    }
    else
    {
      //      Serial.print(" ");
      Serial.print(*memory);
    }

    memory++;
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  Pressed = digitalRead(Switch);
  if (Pressed)
  {
    locatie+=20;
    for (int i = 1; i < locatie; i++)
    {
      Serial.print(" 0x0");
      if (i % 16 == 0)
      {

        Serial.print((int)memory, HEX);
        Serial.println();
      }
      else
      {
        Serial.print(*memory);
      }

      memory++;
    }
    delay(1000);
  }


}
