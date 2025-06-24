//Built-in imports
#include <Arduino.h>

//Test environment imports
#include <unity.h>

//Common imports

//Header import
#include "connectivity.h"

//Project imports
#include "environment.h"

//Connectivity tests
namespace Connectivity {
    void test_device_id_is_not_nullptr() {
        TEST_ASSERT_NOT_NULL_MESSAGE(Environment::DEVICE_ID, "DEVICE_ID is nullptr");
    }

    void test_device_id_is_not_empty() {
        TEST_ASSERT_NOT_EQUAL_MESSAGE('\0', Environment::DEVICE_ID[0], "DEVICE_ID is empty");
    }

    void test_wifi_ssid_is_not_nullptr() {
        TEST_ASSERT_NOT_NULL_MESSAGE(Environment::WIFI_SSID, "WIFI_SSID is nullptr");
    }

    void test_wifi_ssid_not_empty() {
        TEST_ASSERT_NOT_EQUAL_MESSAGE('\0', Environment::WIFI_SSID[0], "WIFI_SSID is empty");
    }

    void test_wifi_password_is_not_nullptr() {
        TEST_ASSERT_NOT_NULL_MESSAGE(Environment::WIFI_PASSWORD, "WIFI_PASSWORD is nullptr");
    }

    void test_wifi_password_not_empty() {
        TEST_ASSERT_NOT_EQUAL_MESSAGE('\0', Environment::WIFI_PASSWORD[0], "WIFI_PASSWORD is empty");
    }

    void test_wifi_mode_valid() {
        TEST_ASSERT_TRUE_MESSAGE(
            Environment::WIFI_MODE == WIFI_MODE_STA ||
            Environment::WIFI_MODE == WIFI_MODE_AP ||
            Environment::WIFI_MODE == WIFI_MODE_NULL,
            "WIFI_MODE is invalid"
        );
    }

    void run_tests(){
        RUN_TEST(Connectivity::test_device_id_is_not_nullptr);
        RUN_TEST(Connectivity::test_device_id_is_not_empty);
        RUN_TEST(Connectivity::test_wifi_ssid_is_not_nullptr);
        RUN_TEST(Connectivity::test_wifi_ssid_not_empty);
        RUN_TEST(Connectivity::test_wifi_password_is_not_nullptr);
        RUN_TEST(Connectivity::test_wifi_password_not_empty);
        RUN_TEST(Connectivity::test_wifi_mode_valid);
    }
}