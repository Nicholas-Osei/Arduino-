byte var1=2;
int var2=7;
char var3='P';
float var4=27.72;

byte *p1;
int *p2;
char *p3;
float *p4;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  p1=&var1;
  Serial.print("Inhoud : ");
  Serial.println(*p1);
  Serial.print("Addres : ");
  Serial.println(int (p1));
  p2=&var2;
  Serial.print("Inhoud : ");
  Serial.println(*p2);
  Serial.print("Addres : ");
  Serial.println(int (p2));
  p3=&var3;
  Serial.print("Inhoud : ");
  Serial.println(*p3);
  Serial.print("Addres : ");
  Serial.println(int (p3));
  p4=&var4;
  Serial.print("Inhoud : ");
  Serial.println(*p4);
  Serial.print("Addres : ");
  Serial.println(int (p4));
}

void loop() {
  // put your main code here, to run repeatedly:

}
