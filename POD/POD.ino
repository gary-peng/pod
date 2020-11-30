#include <avr/sleep.h>

#define WORK_INTERV 300000
#define BREAK_INTERV 60000
#define FLASH_INTERV 250

void setup() {
  for (int i=0; i<=4; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  for (int i=0; i<=4; i++)
  {
    delay(WORK_INTERV);
    digitalWrite(i, LOW);
  }
  delay(1000);

  for (int i=0; i<=9; i++)
  {
    for (int j=0; j<=4; j++)
      digitalWrite(j, HIGH);
    delay(FLASH_INTERV);
    for (int j=0; j<=4; j++)
      digitalWrite(j, LOW);
    delay(FLASH_INTERV);
  }

  // break
  for (int i=0; i<=4; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  for (int i=0; i<=4; i++)
  {
    delay(BREAK_INTERV);
    digitalWrite(i, LOW);
  }
  delay(1000);

  for (int i=0; i<=9; i++)
  {
  for (int j=0; j<=4; j++)
    digitalWrite(j, HIGH);
  delay(FLASH_INTERV);
  for (int j=0; j<=4; j++)
    digitalWrite(j, LOW);
  delay(FLASH_INTERV);
  }

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}

void loop() {}
