#ifndef DEVICE_DISCIPLINE_SELECTOR_H
#define DEVICE_DISCIPLINE_SELECTOR_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "../disciplines/type.h"

namespace Device{
  class DisciplineSelector {
    public:
      //Define a constructor
      DisciplineSelector(const uint8_t selectorPins[2]);

      //Define public methods
      Discipline::Type getSelectedDiscipline();

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