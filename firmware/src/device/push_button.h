#pragma once
#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports


namespace Device {
  class PushButton {
    public:
      //Define destructor, because this is a base class no constructor
      virtual ~PushButton() = 0;
   
      //Define public static methods

      //Define public methods
      void PushButton::Enable();

      //Define public variables

    protected:
      //Define protected methods
      static void IRAM_ATTR interruptHandler();

      //Define protected variables
      uint8_t signalPin = 0;
      static const uint8_t signalActivatedReading = LOW;

    private:
      //Define private methods

      //Define private variables
  };
}
#endif