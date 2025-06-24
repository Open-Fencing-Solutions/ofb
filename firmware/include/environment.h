#pragma once
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

//Built-in Imports
#include <Arduino.h>

//Common imports
#include "esp_wifi.h"

namespace Environment{
    //Connectivity configuration
    constexpr const char* DEVICE_ID = "<HOSTNAME>";         //The hostname of this device
    constexpr wifi_mode_t WIFI_MODE = WIFI_MODE_NULL;       //WIFI_MODE_NULL = OFF, WIFI_MODE_STA = Connect to a WIFI network, WIFI_MODE_AP = Host your own WIFI network
    constexpr const char* WIFI_SSID = "<SSID>";             //The name of the WIFI network
    constexpr const char* WIFI_PASSWORD = "<PASSWORD>";     //The password of the WIFI network

    //Signaling configuration
    constexpr uint8_t BUZZER_PIN = 8;                       //The pin that will control the buzzer output
    constexpr uint8_t RED_LIGHT_PIN = 9;                    //The pin that will control the light for the left (red) side
    constexpr uint8_t GREEN_LIGHT_PIN = 10;                 //The pin that will control the light for the left (green) side

    //Discipline selector configuration - This is for a 3-state tumbler switch
    //For three states only 2 pins are needed
    //The LEFT and RIGHT pins are used for the left switch state \ and the right switch state /
    //If no pin is connected we get the middle state | of the switch
    constexpr uint8_t DISCIPLINE_SELECTOR_PINS[2] = {1, 2}; //The pins that are used to switch the discipline that is active

    //Bout mode selector configuration - This is for a 2-state tumbler switch
    //For two states only 1 one pin is needed using a HIGH or LOW signal
    constexpr uint8_t BOUT_MODE_SELECTOR_PIN = 1;           //The pin that is used to switch the mode that is active

    //Fencer bodycord configuration
    //Array index 0 = Fencer Red (left side of the piste)
    //Array index 1 = Fencer Green (right side of the piste)
    constexpr uint8_t BODYCORD_A_PIN[2] = {1, 4};           //The pins that measure the A pin of the weapons
    constexpr uint8_t BODYCORD_B_PIN[2] = {2, 5};           //The pins that measure the B pin of the weapons
    constexpr uint8_t BODYCORD_C_PIN[2] = {3, 6};           //The pins that measure the C pin of the weapons

    //Piste configuration
    constexpr uint8_t PISTE_PIN = 7;                        //The pin that will measure if a weapon touches the piste
}
#endif