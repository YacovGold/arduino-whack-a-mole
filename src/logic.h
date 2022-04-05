#pragma once

#include "utils.h"

void makeHarder()
{
  auto ledShowDurationMsFactor = 10;
  auto waitBeforeNewLedMsFactor = 5;

  state.ledShowDurationMs = (float)state.ledShowDurationMs / (float)100 * (100 - ledShowDurationMsFactor);
  if (state.ledShowDurationMs < 300)
  {
    state.ledShowDurationMs = 300;
  }

  state.waitBeforeNewLedMs = (float)state.waitBeforeNewLedMs / (float)100 * (100 + waitBeforeNewLedMsFactor);
  if (state.waitBeforeNewLedMs > 5000)
  {
    state.waitBeforeNewLedMs = 5000;
  }
}

void showRandomLed()
{
  int totalOffLeds = 0;
  for (int i = 0; i < LEDS_COUNT; i++)
  {
    if (state.isLedOn[i] == false)
    {
      totalOffLeds++;
    }
  }

  if (totalOffLeds == 0)
  {
    return;
  }

  while (true)
  {
    auto i = random(0, LEDS_COUNT);
    if (state.isLedOn[i] == false)
    {
      changeLed(i, true);
      break;
    }
  }
}

void showNewLedIfNeeded()
{
  if (millis() - state.lastLedOnMs > state.waitBeforeNewLedMs)
  {
    state.lastLedOnMs = millis();
    showRandomLed();
  }
}

void hideTimeoutLeds()
{
  for (int i = 0; i < LEDS_COUNT; i++)
  {
    if (state.isLedOn[i] == true && millis() - state.ledOnFromMs[i] > state.ledShowDurationMs)
    {
      changeLed(i, false);
    }
  }
}