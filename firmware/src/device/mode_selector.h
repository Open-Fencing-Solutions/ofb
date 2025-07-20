#ifndef DEVICE_MODE_SELECTOR_H
#define DEVICE_MODE_SELECTOR_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports


namespace Device{
  enum class Mode {
    TWO_PERSONS,
    ONE_PERSON,
    TRAINING
  };

  class ModeSelector {
    public:
      //Define a constructor
      ModeSelector(const uint8_t selectorPins[2]);

      //Define public methods
      Mode getSelectedMode();

      void handleInterrupts();

      //Define public variables

    protected:
      //Empty for now
      
    private:
      //Define private methods

      //Define private variables
      uint8_t leftPin;
      uint8_t rightPin;
  };
}

#endif