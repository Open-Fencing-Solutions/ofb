//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "../disciplines/type.h"
#include "side.h"
#include "bout.h"

namespace Bout{
  // Constructor and destructor implementation
  Bout::Bout(Discipline::Type disciplineType) : fencers{ //Need to initialize the Fencers in the constructor... :-(
      Fencer(disciplineType, Side::Red),
      Fencer(disciplineType, Side::Green)
  }{
    
  }

  Bout::~Bout(){
    //Clean-up memory of dynamicly allocated variables

  }
}