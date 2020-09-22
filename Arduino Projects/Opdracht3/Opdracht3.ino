#include "SevSeg.h"
SevSeg sevseg; 
void setup()
{
    Serial.begin(9600);
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}
void loop()
{
    //Serial.print("geef een getal");
    Serial.print ("\r\nGeef een getal tussen 0-9: ");
    //waiting for input
    while (Serial.available() == 0);
    int val = Serial.parseInt(); 
    Serial.println(val);
    sevseg.setNumber(val);
    sevseg.refreshDisplay();
}
