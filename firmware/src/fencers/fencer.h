#pragma once
#ifndef FENCER_H
#define FENCER_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "../bouts/side.h"
#include "../disciplines/type.h"
#include "../lames/base.h"
#include "../weapons/base.h"

class Fencer {
  public:
      //Define a constructor and destructor
      Fencer(Discipline::Type disciplineType, Bout::Side side);
      ~Fencer();
  
    //Define public methods

    //Define public variables
    Bout::Side side;
    Lame::Base* lame = nullptr;
    Weapon::Base* weapon = nullptr;
    Fencer* opponent = nullptr; 

  protected:
    //Empty for now

  private:
    //Empty for now
};
#endif