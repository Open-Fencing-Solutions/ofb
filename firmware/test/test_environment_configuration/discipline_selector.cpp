//Built-in imports
#include <Arduino.h>

//Test environment imports
#include <unity.h>

//Common imports

//Header import
#include "discipline_selector.h"

//Project imports
#include "environment.h"

//Connectivity tests
namespace DisciplineSelector {
    void test_discipline_selector_size() {
        TEST_ASSERT_EQUAL_UINT(2, sizeof(Environment::DISCIPLINE_SELECTOR_PINS) / sizeof(Environment::DISCIPLINE_SELECTOR_PINS[0]));
    }

    void test_discipline_selector_pins_are_within_uint8_range() {
       TEST_ASSERT_TRUE_MESSAGE(Environment::DISCIPLINE_SELECTOR_PINS[0] <= 255, "DISCIPLINE_SELECTOR_PINS[0] is outside uint8_t range");
       TEST_ASSERT_TRUE_MESSAGE(Environment::DISCIPLINE_SELECTOR_PINS[1] <= 255, "DISCIPLINE_SELECTOR_PINS[1] is outside uint8_t range");
    }

    void run_tests() {
        RUN_TEST(test_discipline_selector_size);
        RUN_TEST(test_discipline_selector_pins_are_within_uint8_range);
    }
}