#include <runtimer.h>
#define LED 5
#define SENSOR A0
int convert = 0;
singleTimer timerTest;
int del = 500;
void setup()
{
  Serial.begin(9600);
  Serial.flush();
  timerTest.start(10000);
  pinMode(LED, OUTPUT);
}

void loop()
{
  convert = analogRead(SENSOR);
  convert = map(convert, 0, 1023, 255, 0);
  analogWrite(LED, convert);
  delay(del);
  analogWrite(LED, convert / 5);
  delay(del);
  if (timerTest.expired())
  {
    del = 100;
  }
}
