//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "foil.h"
#include "../bouts/side.h"

namespace Lame{
  // Constructor and destructor implementation
  Foil::Foil(){
    pinMode(this->lamePin, INPUT); //Put the lamePin in the correct mode
  }

  Foil::~Foil(){
    pinMode(this->lamePin, INPUT); //Default pin mode is INPUT
  }

  //Public methods
  bool Foil::isHit(){
    return false;
  }
}