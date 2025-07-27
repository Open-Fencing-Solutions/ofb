#pragma once
#ifndef BOUT_H
#define BOUT_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "../fencers/fencer.h"
#include "../device/discipline_mode_selector.h"
#include "../device/bout_mode_selector.h"
#include "../device/signal_mode_selector.h"

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
      State stateMachine;
      Device::DisciplineMode disciplineMode;
      Device::BoutMode boutMode;
      Device::SignalMode signalMode;
      
      

    protected:
      //Empty for now

    private:
      //Empty for now
  };
}
#endif