#pragma once
#ifndef WEAPON_BASE_H
#define WEAPON_BASE_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "../disciplines/type.h"
#include "../bouts/side.h"
#include "../bodycord/bodycord.h"

namespace Weapon {
  class Base {
    public:
      //Define destructor, because this is a base class no constructor
      virtual ~Base() = 0;
   
      //Define public static methods
      static Base* getWeaponByDiscipline(Discipline::Type disciplineType);

      //Define public methods
      void attachBodyCord(Bodycord* bodycord);
      void enable(Bout::Side side);
      void disable();
      bool isActivated();

      //Define public variables

    protected:
      //Define protected methods
      static void IRAM_ATTR redSideInterruptHandler();
      static void IRAM_ATTR greenSideInterruptHandler();

      //Define protected variables
      uint8_t signalPin = 0;
      Bodycord* bodycord = nullptr;
      static const uint8_t signalActivatedReading = LOW;

    private:
      //Define private methods

      //Define private variables
  };
}
#endif