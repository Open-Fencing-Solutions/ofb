//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "foil.h"
#include "../bouts/side.h"


namespace Weapon{
  // Constructor and destructor implementation
  Foil::Foil(){
    pinMode(this->tipPin, INPUT); //Put the tipPin in the correct mode
  }

  Foil::~Foil(){
    deactivate(); //Deactivate (detach interrupt) the weapon
    pinMode(this->tipPin, INPUT); //Default pin mode is INPUT
  }
}