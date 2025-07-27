#ifndef DEVICE_BOUT_MODE_SELECTOR_H
#define DEVICE_BOUT_MODE_SELECTOR_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports


namespace Device{
  enum class BoutMode {
    TWO_PERSONS,
    ONE_PERSON,
    ONE_PERSON_LOCKOUT,
    ARRAY_SIZE
  };

  class BoutModeSelector {
    public:
      //Static instance pointer
      static BoutModeSelector* activeInstance;

      //Define a constructor
      BoutModeSelector(const uint8_t selectorPins[2]);
      ~BoutModeSelector();

      //Define public methods
      void enable(); //Enable the switch and the interupt methods
      void disable(); //Enable the switch and the interupt methods
      BoutMode getSelectedBoutMode(); //Get the bout mode selected by the switch
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