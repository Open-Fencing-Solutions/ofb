#ifndef DEVICE_DISCIPLINE_MODE_SELECTOR_H
#define DEVICE_DISCIPLINE_MODE_SELECTOR_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports


namespace Device{
  class DisciplineMode{
    Foil,
    Sabre,
    Epee,
    ARRAY_SIZE
  };

  class DisciplineModeSelector {
    public:
      //Static instance pointer
      static DisciplineModeSelector* activeInstance;

      //Define a constructor
      DisciplineModeSelector(const uint8_t selectorPins[2]);
      ~DisciplineModeSelector();

      //Define public methods
      void enable(); //Enable the switch and the interupt methods
      void disable(); //Enable the switch and the interupt methods
      Device::DisciplineMode getSelectedDisciplineMode(); //Get the discipline type selected by the switch
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