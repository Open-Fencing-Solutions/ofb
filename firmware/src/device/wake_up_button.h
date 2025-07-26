#pragma once
#ifndef DEVICE_WAKE_UP_BUTTON
#define DEVICE_WAKE_UP_BUTTON

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports


namespace Device {
  class WakeUpButton {
    public:
      //Define constructor and destructor
      WakeUpButton(uint8_t signalPin);
      ~WakeUpButton();
   
      //Define public static methods

      //Define public methods
      void enable();
      void disable();

      //Define public variables

    protected:
      //Define protected methods

      //Define protected variables
      uint8_t signalPin = 0;

    private:
      //Define private methods

      //Define private variables
  };
}
#endif