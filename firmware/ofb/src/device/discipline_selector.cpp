//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "discipline_selector.h"
#include "../disciplines/type.h"

namespace Device{
  // Constructor implementation
  DisciplineSelector::DisciplineSelector(uint8_t selectorPin){
    this->selectorPin = selectorPin;
  }

  Discipline::Type DisciplineSelector::getSelectedDiscipline(){
    return Discipline::Type::Foil;
  }
}