#include "main.h"

stateStruct state;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(btns[0]));
  for (int i = 0; i < BTNS_COUNT; i++)
  {
    pinMode(btns[i], INPUT_PULLUP);
  }
  for (int i = 0; i < LEDS_COUNT; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

  changeLeds(true);
  delay(200);
  changeLeds(false);
  state.lastLedOnMs = millis();
}

void processBtns()
{
  bool btnsClick[BTNS_COUNT];
  getBtnsClick(btnsClick);

  for (int i = 0; i < BTNS_COUNT; i++)
  {
    if (btnsClick[i] == true && state.isLedOn[i] == true)
    {
      changeLed(i, false);
      makeHarder();
      state.score++;
      Serial.println(state.score);
    }
  }
}

void loop()
{
  showNewLedIfNeeded();
  hideTimeoutLeds();
  processBtns();
}
