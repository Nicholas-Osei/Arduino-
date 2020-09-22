#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;
int servoPin = 4;

const int rs = 10, en = 9, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int leds[] = {A0, A1, A2, A3};

//int sw1 = 2;
int sw2 = 3;
int counter = 0;
int menu = 0;
int  collect = 0;

int a = 2;
int b = 11;
//int  counter = 0;
int  state, previous;
int rot_dir = 0;
bool aan = false, confirm = false;;

String HoofdMenu[] = {"Individuele Led", "Kleur"};
String IndividueleLed[] = {"1", "2", "3", "4", "Terug"};
String Kleur[] = {"Rood", "Groen", "Terug"};
String OnOff[] = {"Aan", "Uit"};
char arrow = '>';
int lol  = 0;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  myservo.attach(servoPin);
  for (int i = 0; i < 4; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  //  attachInterrupt(digitalPinToInterrupt(sw1), isrSwitch, RISING);
  attachInterrupt(digitalPinToInterrupt(sw2), isrSwitch2, RISING);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  previous = digitalRead(a);

  attachInterrupt (digitalPinToInterrupt(a), rotaryTurn, CHANGE);

  lcd.begin(16, 4);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  switch (menu)
  {
    case 0:
      HoofdMenuAfdrukken();
      while (menu == 0 )
      {
        rotary(0);
        HoofdMenuAfdrukken();
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
      counter = 0;
      while (menu == 1)
      {
        rotary(1);
        lcd.setCursor(0, 0);
        lcd.print(arrow);
        lcd.setCursor(1, 0);
        lcd.print(IndividueleLed[counter]);
        lcd.setCursor(1, 1);
        lcd.print(IndividueleLed[counter + 1]);
        delay(10);
        if (confirm)
        {
          lcd.clear();
          if (counter == 4)
          {
            menu = 0;
          }
          if (counter == 2)
          {
            menu = 4;
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
        //lcd.clear();
        lcd.setCursor(0, counter);
        lcd.print(arrow);
        lcd.setCursor(1, 0);
        lcd.print(OnOff[0]);
        lcd.setCursor(1, 1);
        lcd.print(OnOff[1]);
        //delay(500);
        rotary(0);
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
        rotary(3);
        //lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(arrow);
        lcd.setCursor(1, 0);
        lcd.print(Kleur[counter]);
        lcd.setCursor(1, 1);
        lcd.print(Kleur[counter + 1]);
        //delay(500);

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
    case 4:
      counter = 0;
      while (menu == 4)
      {
        rotary(5);
        lcd.setCursor(0, 0);
        lcd.print(counter*10);
        myservo.write(counter*10);
      }
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
void rotaryTurn()
{
  rot_dir = digitalRead(a);
  state = 1;
}
void rotary(int limit)
{
  state = digitalRead(a);
  if ((state == LOW ) && (previous == HIGH))
  {
    lcd.clear();
    if (digitalRead(b) == HIGH)
    {
      counter++;
    }
    else
    {
      counter--;
    }
    if (counter < 0)
    {
      counter = 0;
    }
    if (limit == 0)
    {
      if (counter > 1)
      {
        counter = 0;
      }
    }
    else if (limit == 1)
    {
      if (counter > 4)
      {
        counter = 0;
      }
    }
    else if (limit == 3)
    {
      if (counter > 2)
      {
        counter = 0;
      }
    }
    delay(30);

  }
  //Serial.println(counter);
  previous = state;
}
