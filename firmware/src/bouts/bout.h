#pragma once
#ifndef BOUT_H
#define BOUT_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "../disciplines/type.h"
#include "../fencers/fencer.h"
#include "../device/mode_selector.h"

namespace Bout{
  enum class State {
    INIT,
    MONITORING,
    HIT,
    LOCKOUT,
    ARRAY_SIZE
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
      State state;
      Device::Mode mode;
      Discipline::Type discipline;

    protected:
      //Empty for now

    private:
      //Empty for now
  };
}
#endif