//Built-in imports
#include <Arduino.h>

//Test environment imports
#include <unity.h>

//Test imports
#include "bout_mode_selector.h"
#include "connectivity.h"
#include "discipline_selector.h"
#include "signaling.h"

void setup() {
    //NOTE!!! Wait for 3 seconds, else tests won't work on my current Seeed Studio ESP32S3 dev board
    //See more of this on the internet :-(
    delay(3000);

    //Start unit testing
    UNITY_BEGIN();
    BoutModeSelector::run_tests();
    Connectivity::run_tests();
    DisciplineSelector::run_tests();
    Signaling::run_tests();
    UNITY_END();
}

void loop() { }