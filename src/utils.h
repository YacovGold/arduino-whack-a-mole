#pragma once

#include "state.h"

float removePercentage(float value, float percentage)
{
    auto result = value - (value * percentage / 100);
    return result;
}

void changeLed(int i, bool isOn)
{
    state.ledOnFromMs[i] = millis();
    state.isLedOn[i] = isOn;
    digitalWrite(leds[i], isOn ? HIGH : LOW);
}

void changeLeds(bool isOn)
{
    for (int i = 0; i < LEDS_COUNT; i++)
    {
        changeLed(i, isOn);
    }
}

void getBtnsClick(bool btnsRes[])
{
    for (int i = 0; i < BTNS_COUNT; i++)
    {
        if (digitalRead(btns[i]) == LOW)
        {
            if (state.isBtnDown[i] == false)
            {
                state.isBtnDown[i] = true;
                btnsRes[i] = true;
            }
            else
            {
                btnsRes[i] = false;
            }
        }
        else
        {
            state.isBtnDown[i] = false;
            btnsRes[i] = false;
        }
    }
}

void blink(ulong durationMs, int repeat)
{
    for (int i = 0; i < repeat; i++)
    {
        changeLeds(true);
        delay(durationMs);
        changeLeds(false);
        delay(durationMs);
    }
}