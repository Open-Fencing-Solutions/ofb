#ifndef WEAPON_FOIL_H
#define WEAPON_FOIL_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Base class import
#include "base.h"

//Project imports
#include "../bouts/side.h"

namespace Weapon{
  class Foil : public Base {
    public:
      //Define a constructor and destructor
      Foil();
      ~Foil();

      //Define public static methods

      //Define public methods

      //Define public variables
 
    protected:
      //Define protected methods
      

      //Define protected variables
      const uint8_t tipPin = 1;
      static const uint8_t isDepressedValue = HIGH;

    private:
      //Define private methods

      //Define private variables
      
  };
}

#endif