#ifndef DEVICE_SIGNAL_MODE_SELECTOR_H
#define DEVICE_SIGNAL_MODE_SELECTOR_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports


namespace Device{
  enum class SignalMode {
    LED_AND_BUZZER,
    ONLY_LED,
    ONLY_BUZZER,
    ARRAY_SIZE //Use this integer as a array size without hardcoding :-)
  };

  class SignalModeSelector {
    public:
      //Static instance pointer
      static SignalModeSelector* activeInstance;

      //Define a constructor
      SignalModeSelector(const uint8_t selectorPins[2]);
      ~SignalModeSelector();

      //Define public methods
      void enable(); //Enable the switch and the interupt methods
      void disable(); //Enable the switch and the interupt methods
      SignalMode getSelectedSignalMode(); //Get the signal mode selected by the switch
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