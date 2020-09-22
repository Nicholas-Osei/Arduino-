int sw = 2;
int led = 3;
bool check = false;
int num = 0;
float state, reading, previous;
long tijd = 0, debounce = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(sw, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  //reading=digitalRead(sw);

}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(sw);

  if (reading == LOW && previous == HIGH)
  {
    if ((millis() - tijd) > debounce)
    {

      num++;
      Serial.println(num);
      if (state == HIGH)
      {
        state = LOW;

      }
      else
      {
        state = HIGH;

      }
      tijd = millis();
    }

  }
  digitalWrite(led, state);
  previous = reading;


}
