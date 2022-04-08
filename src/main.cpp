#include "main.h"

stateStruct state;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A5));
  for (int i = 0; i < BTNS_COUNT; i++)
  {
    pinMode(btns[i], INPUT_PULLUP);
  }
  for (int i = 0; i < LEDS_COUNT; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

  blink(BLINK_DURATION_MS, 1);

  state.lastLedOnMs = millis();
}

void loop()
{
  showNewLedIfNeeded();
  hideTimeoutLeds();
  processBtns();
}
