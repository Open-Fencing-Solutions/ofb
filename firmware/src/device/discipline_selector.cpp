//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "discipline_selector.h"
#include "../disciplines/type.h"

namespace Device{
  // Constructor implementation
  DisciplineSelector::DisciplineSelector(const uint8_t selectorPins[2]){
    this->leftPin = selectorPins[0];
    this->rightPin = selectorPins[1];
  }

  Discipline::Type DisciplineSelector::getSelectedDiscipline(){
    return Discipline::Type::Foil;
  }
}