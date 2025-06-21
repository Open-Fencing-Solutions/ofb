#pragma once
#ifndef BOUT_H
#define BOUT_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "../disciplines/type.h"
#include "../fencers/fencer.h"

namespace Bout{
  class Bout {
    public:
        //Define a constructor and destructor
        Bout(Discipline::Type disciplineType);
        ~Bout();
    
      //Define public methods

      //Define public variables
      //Piste piste;
      Fencer fencers[2];


    protected:
      //Empty for now

    private:
      //Empty for now
  };
}
#endif