//Built-in imports
#include <Arduino.h>

//Test environment imports
#include <unity.h>

//Test imports
#include "connectivity.h"

void setup() {
    //NOTE!!! Wait for 3 seconds, else tests won't work on my current Seeed Studio ESP32S3 dev board
    //See more of this on the internet :-(
    delay(3000);

    //Start unit testing
    UNITY_BEGIN();
    connectivity::run_tests();
    signals::run_tests();
    UNITY_END();
}

void loop() { }