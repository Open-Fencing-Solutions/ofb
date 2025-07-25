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
      //Static instance pointer
      static ModeSelector* activeInstance;

      //Define a constructor
      ModeSelector(const uint8_t selectorPins[2]);
      ~ModeSelector();

      //Define public methods
      Mode getSelectedMode();

      void handleInterrupts();

      //Define public variables

    protected:
      //empty for now
      
    private:
      //Define private methods
      static void IRAM_ATTR interruptHandler();

      //Define private variables
      uint8_t topPin;
      uint8_t bottomPin;
      bool interruptTriggered = false;

  };
}

#endif