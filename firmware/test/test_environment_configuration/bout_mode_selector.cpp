//Built-in imports
#include <Arduino.h>

//Test environment imports
#include <unity.h>

//Common imports

//Header import
#include "bout_mode_selector.h"

//Project imports
#include "environment.h"

//Connectivity tests
namespace BoutModeSelector {
    void test_bout_mode_selector_pin_is_within_uint8_range() {
        TEST_ASSERT_TRUE_MESSAGE(Environment::BOUT_MODE_SELECTOR_PIN <= 255, "BOUT_MODE_SELECTOR_PIN is outside uint8_t range");
    }

    void run_tests() {
        RUN_TEST(test_bout_mode_selector_pin_is_within_uint8_range);
    }
}