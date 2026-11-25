/**
 * @file main.cpp
 */

#include <Arduino.h>
#include "board.h"

int cycle_time = 1000;
int duty_rate = 50;
int p1, p2, p3;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(BUTTON_1,BUTTON_MODE);
  pinMode(BUTTON_2,BUTTON_MODE);
  pinMode(BUTTON_3,BUTTON_MODE);

  p1 = digitalRead(BUTTON_1);
  p2 = digitalRead(BUTTON_2);
  p3 = digitalRead(BUTTON_3);
}

void loop() {
  // put your main code here, to run repeatedly:
  int c1 = digitalRead(BUTTON_1);
  int c2 = digitalRead(BUTTON_2);
  int c3 = digitalRead(BUTTON_3);
  if (c1 != p1 && c1 == BUTTON_ACTIVE){
    cycle_time += 100;
  }
  if (c2 != p2 && c2 == BUTTON_ACTIVE){
    cycle_time -= 100;
    if (cycle_time < 100){cycle_time = 100;}
  }
  if (c3 != p3 && c3 == BUTTON_ACTIVE){
    duty_rate = (duty_rate + 25) % 100;
  }

  int time_on = (cycle_time / 100) * duty_rate;
  int time_passed_on = millis()%cycle_time;

  if (time_passed_on < time_on){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  p1 = c1;
  p2 = c2;
  p3 = c3;
}
