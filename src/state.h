#pragma once

#include "board_config.h"
#include "game_config.h"

const int btns[BTNS_COUNT] = {BTN_YELLOW, BTN_BLUE, BTN_GREEN, BTN_RED};
const int leds[LEDS_COUNT] = {LED_YELLOW, LED_BLUE, LED_GREEN, LED_RED};

typedef unsigned long ulong;

struct stateStruct
{
    int score = 0;
    int currentLevel = 1;

    ulong ledShowDurationMs = INIT_LED_SHOW_DURATION_MS;
    ulong waitBeforeNewLedMs = INIT_WAIT_BEFORE_NEW_LED_MS;

    ulong lastLedOnMs = 0;

    bool isBtnDown[BTNS_COUNT];
    bool isLedOn[LEDS_COUNT];

    ulong ledOnFromMs[LEDS_COUNT];
};

extern stateStruct state;
