#include <EEPROM.h>
String userInputs[3];
int adres = 0x00;
bool Terug = false;
int AantalKeerUit = 0;
String  vraag;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Geef in 3 strings gescheiden door komma en eindigend op punt");
  AantalKeerUit = EEPROM.read(adres);
  AantalKeerUit++;
  EEPROM.write(adres, AantalKeerUit);
  if (AantalKeerUit > 0)
  {
    for (int i = 0; i < 3; i++)
    {
      Serial.println(userInputs[i]);
    }
  }
  EEPROM.get(adres, userInputs);
}

void loop() {
  // put your main code here, to run repeatedly:
//  while (Terug)
//  {
    while(Serial.available() > 0)
    {
      userInputs[0] = Serial.readStringUntil(',');
      userInputs[1] = Serial.readStringUntil(',');
      userInputs[2] = Serial.readStringUntil(',');
      for (int i = 0; i < 3; i++)
      {
        Serial.println(userInputs[i]);
      }
      Serial.println("Is dit ok?");
      vraag = Serial.readStringUntil('\n');
      if (vraag== "j")
      {
        Serial.println(" ok?");
        EEPROM.put(adres, userInputs);
        Terug = false;
      }
      else if (vraag == "n")
      {
        Terug = true;
        Serial.println("Geef in 3 strings gescheiden door komma en eindigend op punt");
      }
    }
//  }





}
