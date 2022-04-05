#pragma once

#include "board_config.h"

const int btns[BTNS_COUNT] = {BTN_YELLOW, BTN_BLUE, BTN_GREEN, BTN_RED};
const int leds[LEDS_COUNT] = {LED_YELLOW, LED_BLUE, LED_GREEN, LED_RED};

typedef unsigned long ulong;

struct stateStruct
{
    int score = 0;

    ulong ledShowDurationMs = 3000;
    ulong waitBeforeNewLedMs = 900;

    ulong lastLedOnMs = 0;

    bool isBtnDown[BTNS_COUNT];
    bool isLedOn[LEDS_COUNT];

    ulong ledOnFromMs[LEDS_COUNT];
};

extern stateStruct state;
