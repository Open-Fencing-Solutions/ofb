#include <unity.h>
#include "environment.h"

void test_device_id_not_empty() {
    TEST_ASSERT_NOT_EQUAL_MESSAGE('\0', environment::DEVICE_ID[0], "DEVICE_ID is empty");
}

void test_wifi_ssid_not_empty() {
    TEST_ASSERT_NOT_EQUAL_MESSAGE('\0', environment::WIFI_SSID[0], "WIFI_SSID is empty");
}

void test_wifi_password_not_empty() {
    TEST_ASSERT_NOT_EQUAL_MESSAGE('\0', environment::WIFI_PASSWORD[0], "WIFI_PASSWORD is empty");
}

void test_wifi_mode_valid() {
    TEST_ASSERT_TRUE_MESSAGE(
        environment::WIFI_MODE == WIFI_MODE_STA ||
        environment::WIFI_MODE == WIFI_MODE_AP ||
        environment::WIFI_MODE == WIFI_MODE_NULL,
        "WIFI_MODE is invalid"
    );
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_device_id_not_empty);
    RUN_TEST(test_wifi_ssid_not_empty);
    RUN_TEST(test_wifi_password_not_empty);
    RUN_TEST(test_wifi_mode_valid);
    UNITY_END();
}

void loop() {
    // not used
}