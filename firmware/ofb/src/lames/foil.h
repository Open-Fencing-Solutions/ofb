#ifndef LAME_FOIL_H
#define LAME_FOIL_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Base class import
#include "base.h"

//Custom imports 
#include "base.h"

namespace Lame{
  class Foil : public Base {
    public:
      //Define a constructor and destructor
      Foil();
      ~Foil();

      //Define public methods
      bool isHit() override;

      //Define public variables

    protected:
      //Define protected methods

      //Define protected variables
      uint8_t lamePin = A2;
      
    private:
      //Define private methods

      //Define private variables
  };
}

#endif