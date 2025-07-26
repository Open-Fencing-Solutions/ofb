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
    TRAINING,
    ARRAY_SIZE
  };

  class ModeSelector {
    public:
      //Static instance pointer
      static ModeSelector* activeInstance;

      //Define a constructor
      ModeSelector(const uint8_t selectorPins[2]);
      ~ModeSelector();

      //Define public methods
      void enable(); //Enable the switch and the interupt methods
      void disable(); //Enable the switch and the interupt methods
      Mode getSelectedMode(); //Get the device mode selected by the switch
      void handleInterrupts(); //Method that is triggered by the interrupt flag

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