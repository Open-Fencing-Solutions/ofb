//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "base.h"
#include "foil.h"
#include "../disciplines/type.h"

namespace Lame{
  // Destructor implementation
  Base::~Base(){

  }

  // Static method implementation to return a Lame instance pointer
  Base* Base::getLameByDiscipline(Discipline::Type disciplineType) {
    switch(disciplineType){
      case Discipline::Type::Foil: return new Lame::Foil();
      case Discipline::Type::Sabre: return new Lame::Foil(); // Placeholder until Sabre is implemented
      case Discipline::Type::Epee: return nullptr; // Placeholder until Epee is implemented
      default: return nullptr;
    }
  }
}