#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int leds[] = {A0, A1, A2, A3};

int sw1 = 2;
int sw2 = 3;
int counter = 0;
int menu = 0;
int  collect = 0;

bool aan = false, confirm = false;;

String HoofdMenu[] = {"Individuele Led", "Kleur"};
String IndividueleLed[] = {"1", "2", "3", "4", "Terug"};
String Kleur[] = {"Rood", "Groen", "Terug"};
String OnOff[] = {"Aan", "Uit"};
char arrow = '>';
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(sw1), isrSwitch, RISING);
  attachInterrupt(digitalPinToInterrupt(sw2), isrSwitch2, RISING);
  lcd.begin(16, 5);

}

void loop() {
  // put your main code here, to run repeatedly:
  switch (menu)
  {
    case 0:
      HoofdMenuAfdrukken();
      while (menu == 0)
      {
        if (aan)
        {
          lcd.clear();
          counter++;
          if (counter > 1)
          {
            counter = 0;
          }
          HoofdMenuAfdrukken();
          delay(500);
          aan = false;
        }
        if (confirm)
        {
          if (counter == 0)
          {
            menu = 1;
          }
          else
          {
            menu = 3;
          }
          delay(500);
          confirm = false;
        }
      }
      break;
    case 1:
      while (menu == 1)
      {
        if (confirm == false)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(arrow);
          lcd.setCursor(1, 0);
          lcd.print(IndividueleLed[counter]);
          lcd.setCursor(1, 1);
          lcd.print(IndividueleLed[counter + 1]);
          delay(500);
        }
        if (aan)
        {
          counter++;
          if (counter > 4)
          {
            counter = 0;
          }
          delay(500);
          aan = false;
        }
        if (confirm)
        {
          lcd.clear();
          if (counter == 4)
          {
            menu = 0;
          }
          else
          {
            collect = counter;
            menu = 2;
          }
        }
        confirm = false;
      }
      break;
    case 2:
      counter = 0;
      while (menu == 2)
      {
        lcd.clear();
        lcd.setCursor(0, counter);
        lcd.print(arrow);
        lcd.setCursor(1, 0);
        lcd.print(OnOff[0]);
        lcd.setCursor(1, 1);
        lcd.print(OnOff[1]);
        delay(500);
        if (aan)
        {
          counter++;
          if (counter > 1)
          {
            counter = 0;
          }
          delay(500);
          aan = false;
        }
        if (confirm)
        {
          if (counter == 0)
          {
            digitalWrite(leds[collect], HIGH);
          }
          else
          {
            digitalWrite(leds[collect], LOW);
          }
          delay(500);
          menu = 0;
          confirm = false;
        }
      }
      break;
    case 3:
      counter = 0;
      while (menu == 3)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(arrow);
        lcd.setCursor(1, 0);
        lcd.print(Kleur[counter]);
        lcd.setCursor(1, 1);
        lcd.print(Kleur[counter + 1]);
        delay(500);
        if (aan)
        {
          counter++;
          if (counter > 2)
          {
            counter = 0;
          }
          delay(500);
          aan = false;
        }
        if (confirm)
        {
          if (counter == 2)
          {
            menu = 0;
          }
          else
          {
            collect = counter;
            menu = 2;
          }
          confirm = false;
        }
      }
      break;
  }
}
void isrSwitch()
{
  aan = true;
}
void isrSwitch2()
{
  confirm = true;
}
void HoofdMenuAfdrukken()
{
  lcd.setCursor(0, counter);
  lcd.print(arrow);
  lcd.setCursor(1, 0);
  lcd.print(HoofdMenu[0]);
  lcd.setCursor(1, 1);
  lcd.print(HoofdMenu[1]);
}
