byte variable = 1;
int nummer = 10;
char letter = 'a';
float getallen = 3.5;


byte *bytepointer ;
int *intpointer ;
char *charpointer ;
float *floatpointer ;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bytepointer = &variable;
  intpointer = &nummer;
  charpointer = &letter;
  floatpointer = &getallen;
  Serial.print("Type: ");
  Serial.print("Byte - ");

  Serial.print(" Address: ");
  Serial.print((int)bytepointer);

  Serial.print(" Inhoud: ");
  Serial.println(*bytepointer);

  Serial.print("Type: ");
  Serial.print("Int - ");

  Serial.print("Address: ");
  Serial.print((int)intpointer);

  Serial.print(" Inhoud: ");
  Serial.println(*intpointer);

  Serial.print("Type: ");
  Serial.print("Char - ");

  Serial.print("Address: ");
  Serial.print((int)charpointer);

  Serial.print(" Inhoud: ");
  Serial.println(*charpointer);

  Serial.print("Type: ");
  Serial.print("Float - ");

  Serial.print("Address: ");
  Serial.print((int)floatpointer);

  Serial.print(" Inhoud: ");
  Serial.println(*floatpointer);

  




}

void loop() {
  // put your main code here, to run repeatedly:




}
