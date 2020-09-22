int Switch = 2;
bool Pressed;

//char addres[] = {0x0100,0x0110,0x0120};
char *memory ;



void setup() {
  // put your setup code here, to run once:
  pinMode(Switch, INPUT);
  Serial.begin(9600);
  memory = (char *)  0x0100;
  for (int i = 1; i < 2049; i++)
  {
    Serial.print(" 0x0");
    if (i % 16 == 0)
    {
      
      Serial.print((int)memory, HEX);
//      Serial.print(" ");
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
    Serial.println("aan");
    delay(1000);
  }


}
