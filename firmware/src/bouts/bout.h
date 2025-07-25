#pragma once
#ifndef BOUT_H
#define BOUT_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "../disciplines/type.h"
#include "../fencers/fencer.h"

namespace Bout{
  enum class State {
    INIT,
    MONITORING,
    HIT,
    LOCKOUT,
  };

  class Bout{
    public:
      //Define a constructor and destructor
      Bout();
      ~Bout();
    
      //Define public methods

      //Define public variables
      //Piste piste;
      //Fencer fencers[2];
      State state = State::INIT;
      Discipline::Type discipline;

    protected:
      //Empty for now

    private:
      //Empty for now
  };
}
#endif