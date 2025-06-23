#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

//Built-in Imports
#include <Arduino.h>

namespace environment{
    //Device configuration
    const char* const DEVICE_ID = "OFB-01";

    //Signaling configuration
    const uint8_t BUZZER_PIN = 8;
    const uint8_t RED_LIGHT_PIN = 9;
    const uint8_t GREEN_LIGHT_PIN = 10;

    //Piste configuration
    const uint8_t PISTE_PIN = 7;

    //Discipline selector configuration - This is for a 3-state tumbler switch
    //The LEFT and RIGHT pins are used for the left switch state \ and the right switch state /
    //If no pin is connected we get the middle state | of the switch
    const uint8_t DISCIPLINE_SELECTOR_PINS[2] = {1, 2};

    //Bout mode selector switch - This is for a 2-state tumbler switch
    const uint8_t BOUT_MODE_SELECTOR_PINS[2] = {1, 2};

    //Fencer bodycord configuration
    //Array index 0 = Fencer Red (left side of the piste)
    //Array index 1 = Fencer Green (right side of the piste)
    const uint8_t BODYCORD_A_PIN[2] = {1, 4};
    const uint8_t BODYCORD_B_PIN[2] = {2, 5};
    const uint8_t BODYCORD_C_PIN[2] = {3, 6};

    //WIFI settings - not implemented but a example for the future
    const char* const WIFI_MODE = "";
    const char* const WIFI_SSID = "";
    const char* const WIFI_PASSWORD = "";
}
#endif