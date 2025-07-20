//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "foil.h"
#include "../bouts/side.h"


namespace Weapon{
  // Constructor and destructor implementation
  Foil::Foil(){
    pinMode(this->signalPin, INPUT); //Put the signalPin in the correct mode
  }

  Foil::~Foil(){
    disable(); //Disable (detach interrupt) the weapon
    pinMode(this->signalPin, INPUT); //Default pin mode is INPUT
  }
}