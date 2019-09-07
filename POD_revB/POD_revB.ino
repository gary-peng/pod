#include <avr/sleep.h>

#define workInterv 300000
#define breakInterv 60000
#define flashInterv 250

void setup()
{
  for(int i=0; i<=4; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  for(int i=0; i<=4; i++)
  {
    delay(workInterv);
    digitalWrite(i, LOW);
  }
  delay(1000);

  for(int i=0; i<=9; i++)
  {
    for(int j=0; j<=4; j++)
      digitalWrite(j, HIGH);
    delay(flashInterv);
    for(int j=0; j<=4; j++)
      digitalWrite(j, LOW);
    delay(flashInterv);
  }

  // break
  for(int i=0; i<=4; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  for(int i=0; i<=4; i++)
  {
    delay(breakInterv);
    digitalWrite(i, LOW);
  }
  delay(1000);

  for(int i=0; i<=9; i++)
  {
    for(int j=0; j<=4; j++)
      digitalWrite(j, HIGH);
    delay(flashInterv);
    for(int j=0; j<=4; j++)
      digitalWrite(j, LOW);
    delay(flashInterv);
  }

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}

void loop()
{
}
