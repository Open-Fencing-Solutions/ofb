#pragma once
#ifndef LAME_BASE_H
#define LAME_BASE_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "../disciplines/type.h"
#include "../bouts/side.h"

namespace Lame {
  class Base {
    public:
      //Define destructor, because this is a base class no constructor
      virtual ~Base() = 0;
   
      //Define public static methods
      static Base* getLameByDiscipline(Discipline::Type disciplineType);

      //Define public methods
      virtual bool isHit() = 0;

      //Define public variables

    protected:
      //Define protected methods

      //Define protected variables
      uint8_t lamePin;

    private:
      //Define private methods

      //Define private variables
  };
}
#endif