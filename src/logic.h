#pragma once

#include "utils.h"

void makeHarder(int factor)
{
  auto ledShowDurationMsFactor = factor * 2;
  auto waitBeforeNewLedMsFactor = factor;

  state.ledShowDurationMs = removePercentage(state.ledShowDurationMs, ledShowDurationMsFactor);
  if (state.ledShowDurationMs < MIN_LED_SHOW_DURATION_MS)
  {
    state.ledShowDurationMs = MIN_LED_SHOW_DURATION_MS;
  }

  Serial.println(state.waitBeforeNewLedMs);
  state.waitBeforeNewLedMs = removePercentage(state.waitBeforeNewLedMs, waitBeforeNewLedMsFactor * -1 /* we add percentage instead of removing */);
  if (state.waitBeforeNewLedMs > MAX_WAIT_BEFORE_NEW_LED_MS)
  {
    state.waitBeforeNewLedMs = MAX_WAIT_BEFORE_NEW_LED_MS;
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

void processBtns()
{
  bool btnsClick[BTNS_COUNT];
  getBtnsClick(btnsClick);

  for (int i = 0; i < BTNS_COUNT; i++)
  {
    if (btnsClick[i] == true)
    {
      if (state.isLedOn[i] == true)
      {
        changeLed(i, false);
        state.score += SCORE_INCREMENT_PER_GOOD_CLICK;
        Serial.println(state.score);

        if (state.score >= state.currentLevel * SCORE_NEEDED_TO_LEVEL_UP)
        {
          state.currentLevel++;
          makeHarder(MAKE_HARDER_FACTOR);
          blink(BLINK_DURATION_MS, state.currentLevel);
        }
      }
      else
      { // btn cliked but led is off
        state.score -= SCORE_DECREMENT_PER_BAD_CLICK;
      }
    }
  }
}