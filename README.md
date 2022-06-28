# WhackAMole-Arduino

Install [PlatformIO](https://platformio.org/platformio-ide) extenssion in vscode

Then configure the 'board_config.h' file with the correct pins

You can also config in the file 'game_config.h' the game options:

`INIT_LED_SHOW_DURATION_MS`

Setup: Time light shows per millisecond. Example: 1000 = 1 second. 

`INIT_WAIT_BEFORE_NEW_LED_MS`

Setup: Time between lights displayed. 

`MIN_LED_SHOW_DURATION_MS`

As the levels get harder, the light show duration (LEDs) will show less and less time but won’t go below this value.

`MAX_WAIT_BEFORE_NEW_LED_MS`

As the levels get harder, the time in between light displays will get higher before another light shows, it’ll take more time until the next light shows but won’t go over this value.



`SCORE_NEEDED_TO_LEVEL_UP`

Every time the score goes up by this amount of points, the player goes to a harder level.
Example: if you set this to 10, when the score gets to 10 the player will level up. When the player gets to 20 he will level up, and 30, 40 etc.


`SCORE_INCREMENT_PER_RIGHT_CLICK`

A “right” click is when the player clicks on the appropriate button meaning the same color as the LED display. Every “right” click will increase the score by this value.


`SCORE_DECREMENT_PER_WRONG_CLICK`

A “wrong” click is when the player clicks on the inappropriate button meaning not the same color as the LED display. Every “wrong” click will decrease the score by this value.


`MAKE_HARDER_FACTOR`

The higher the value, the harder and faster the lights will display.

Each higher level, the time decreases but will never go under this value `MIN_LED_SHOW_DURATION_MS`

And will not go over this value `INIT_WAIT_BEFORE_NEW_LED_MS`


`BLINK_DURATION_MS`

When leveling up or when starting, the LEDs will blink in this duration

