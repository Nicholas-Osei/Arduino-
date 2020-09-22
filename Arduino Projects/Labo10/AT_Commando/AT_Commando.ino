
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11); // CONNECT BT RX PIN TO ARDUINO 11 PIN | CONNECT BT TX PIN TO ARDUINO 10 PIN

void setup() 
{

  BTSerial.begin(38400);  // HC-05 default speed in AT command more
  Serial.begin(38400);
  Serial.println("Enter AT commands:");
  
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
  {
    Serial.write(BTSerial.read());
  }
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    BTSerial.write(Serial.read());
  }
}
