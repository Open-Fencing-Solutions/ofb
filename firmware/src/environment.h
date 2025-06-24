#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

//Built-in Imports
#include <Arduino.h>

//Common imports
#include "esp_wifi.h"

namespace environment{
    //Connectivity settings - not implemented but a example for the future
    constexpr const char* DEVICE_ID = "OFB-01";
    constexpr wifi_mode_t WIFI_MODE = WIFI_MODE_NULL; //WIFI_MODE_NULL = OFF, WIFI_MODE_STA = Connect to a WIFI network, WIFI_MODE_AP = Host your own WIFI network
    constexpr const char* WIFI_SSID = ""; //The name of the WIFI network
    constexpr const char* WIFI_PASSWORD = ""; //The password of the WIFI network

    //Signaling configuration
    constexpr uint8_t BUZZER_PIN = 8;
    constexpr uint8_t RED_LIGHT_PIN = 9;
    constexpr uint8_t GREEN_LIGHT_PIN = 10;

    //Piste configuration
    constexpr uint8_t PISTE_PIN = 7;

    //Discipline selector configuration - This is for a 3-state tumbler switch
    //For three states only 2 pins are needed
    //The LEFT and RIGHT pins are used for the left switch state \ and the right switch state /
    //If no pin is connected we get the middle state | of the switch
    constexpr uint8_t DISCIPLINE_SELECTOR_PINS[2] = {1, 2};

    //Bout mode selector switch - This is for a 2-state tumbler switch
    //For two states only 1 one pin is needed using a HIGH or LOW signal
    constexpr uint8_t BOUT_MODE_SELECTOR_PIN = 1;

    //Fencer bodycord configuration
    //Array index 0 = Fencer Red (left side of the piste)
    //Array index 1 = Fencer Green (right side of the piste)
    constexpr uint8_t BODYCORD_A_PIN[2] = {1, 4};
    const uint8_t BODYCORD_B_PIN[2] = {2, 5};
    const uint8_t BODYCORD_C_PIN[2] = {3, 6};
}
#endif