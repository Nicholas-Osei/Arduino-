int i[10] = { 1, 2, 3, 4, 5, 6, 7, 8 , 9, 0 };
int led = 3;
int *pointer = i;
bool ToonAdres;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (*pointer == 0 )
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
  roteer(i);
  delay(100);


}

void roteer(int *p)
{



  int *temp;
  *temp = *(p) ;
  for (int i = 0; i < 9; i++)
  {
    *p = *(p + 1);
    p++;
  }
  *(p) = *temp ;
  p = p - 9;

  if (!ToonAdres)   
  {
    Serial.println("Adressen: ");

    for (int i = 0; i < 10; i++)
    {
      Serial.print(int(p));
      Serial.print(" ");
      p++;
    }

    p = p - 10;              
    ToonAdres = true;
    Serial.println(" Array Inhoud:");
  }

  for (int i = 0; i < 10; i++)
  {
    Serial.print(*p);
    Serial.print(" ");
    p++;
  }
  Serial.println(" ");
  p = p - 10;    
  delay(1000);


}
