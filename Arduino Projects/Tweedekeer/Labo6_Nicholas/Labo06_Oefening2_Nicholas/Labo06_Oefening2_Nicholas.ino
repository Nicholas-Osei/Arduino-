#include <EEPROM.h>
int AantalKeerUit=0;
int GeheugenAddress=0x00;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  AantalKeerUit= EEPROM.read(GeheugenAddress);
  Serial.println(AantalKeerUit);
  AantalKeerUit++;

  EEPROM.write(GeheugenAddress,AantalKeerUit);
  

}

void loop() {
  // put your main code here, to run repeatedly:


}
