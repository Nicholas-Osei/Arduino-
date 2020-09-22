int analoog;
float voltage;
void setup() {
for(int i=2;i<=6;i++)
{
  pinMode(i, OUTPUT);
}
  Serial.begin(9600);
}

void loop() { 
  analoog = analogRead(3);
  voltage = analoog /20;
  Serial.print("0");
  for(int i =0;i < voltage;i++){
  Serial.print("+");
  }

  Serial.println("");
}
