#define SegA   12
#define SegB   11
#define SegC   10
#define SegD    9
#define SegE    8
#define SegF    7
#define SegG    6
#define Dig1    5
#define Dig2    4
#define Dig3    3
#define Dig4    2
 
byte   current_digit, last_read;
int8_t quad = 0, change;
int    enc_value = 0;
 
void setup()
{
  pinMode(SegA, OUTPUT);
  pinMode(SegB, OUTPUT);
  pinMode(SegC, OUTPUT);
  pinMode(SegD, OUTPUT);
  pinMode(SegE, OUTPUT);
  pinMode(SegF, OUTPUT);
  pinMode(SegG, OUTPUT);
  pinMode(Dig1, OUTPUT);
  pinMode(Dig2, OUTPUT);
  pinMode(Dig3, OUTPUT);
  pinMode(Dig4, OUTPUT);
 
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  last_read = digitalRead(A5) << 1 | digitalRead(A4);
  disp_off();  

  TCCR1A = 0;
  TCCR1B = 1;  
  TCNT1  = 0;  
  TIMSK1 = 1;  
 

  PCICR  = 2;      
  PCMSK1 = 0x30;   
 
}
 
ISR(TIMER1_OVF_vect)   
{
  disp_off();  
  uint16_t abs_value = abs(enc_value);  
 
  switch (current_digit)
  {
    case 1:
      if(enc_value < 0)  
      {  
        disp(10);  
        digitalWrite(Dig1, LOW);  
      }
      break;
 
    case 2:
      disp( (abs_value / 100) % 10);   
      digitalWrite(Dig2, LOW);     
      break;
 
    case 3:
      disp( (abs_value / 10) % 10);  
      digitalWrite(Dig3, LOW);   
      break;
 
    case 4:
      disp(abs_value % 10);   
      digitalWrite(Dig4, LOW);  
  }
 
  current_digit = (current_digit % 4) + 1;
}
 
ISR (PCINT1_vect)  
  uint8_t encoderRead = 0;
 
  encoderRead = digitalRead(A5) << 1 | digitalRead(A4);
 
  if(encoderRead == last_read)
    return;
 
  if(bitRead(encoderRead, 0) == bitRead(last_read, 1))
    quad -= 1;
  else
    quad += 1;
  last_read = encoderRead; 
}
 
int8_t EncoderGet(void)
{
  int8_t val = 0;
  while(quad >= 4){
    val += 1;
    quad -= 4;
  }
  while(quad <= -4){
    val -= 1;
    quad += 4;
  }
  return val;
}
 
// main loop
void loop()
{
  change = EncoderGet();
  if(change)
    enc_value += change;
  delay(100);  
}
 
void disp(byte number)
{
  switch (number)
  {
    case 0:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      break;
 
    case 1:  
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
 
    case 2:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break;
 
    case 3:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      break;
 
    case 4:  
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
 
    case 5:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
 
    case 6:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
    
    case 7:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      break;
 
    case 8:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
 
    case 9:  
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      break;
 
    case 10:  
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
  }
}
 
void disp_off()
{
   digitalWrite(Dig1, HIGH);
   digitalWrite(Dig2, HIGH);
   digitalWrite(Dig3, HIGH);
   digitalWrite(Dig4, HIGH);
}
 
