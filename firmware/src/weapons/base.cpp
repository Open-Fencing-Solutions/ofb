//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "base.h"
#include "foil.h"
#include "../bouts/side.h"
#include "../disciplines/type.h"

namespace Weapon{
  // Destructor implementation
  Base::~Base(){

  }

  //Two static interupt methods one for each side. This is needed because interupts can't pass an side argument.
  //IRAM_ATTR makes sure the method is in memory for the fastest execution possible
  void IRAM_ATTR Base::redSideInterruptHandler(){
    unsigned long aaa = micros();
  }

  
  void IRAM_ATTR Base::greenSideInterruptHandler(){
    unsigned long interruptTime = micros();

  }


  void Base::activate(Bout::Side side){
    //Initialize a method pointer for storing the interrupt handler
    void (*interruptHandler)() = nullptr;

    //Select a interrupt handler
    if (side == Bout::Side::Red) {
        interruptHandler = redSideInterruptHandler;
    } else if (side == Bout::Side::Green) {
        interruptHandler = greenSideInterruptHandler;
    }

    //Activate the interrupt with the selected handler
    attachInterrupt(digitalPinToInterrupt(this->tipPin), interruptHandler, CHANGE);
  }

  void Base::deactivate(){
    //Activate the interrupt with the selected handler
    detachInterrupt(digitalPinToInterrupt(this->tipPin));
  }

  bool Base::isDepressed(){
    //Compare the reading of the tip against the value that it should be
    return digitalRead(this->tipPin) == isDepressedValue;
  }


  // Static method implementation to return a Weapon instance pointer
  Base* Base::getWeaponByDiscipline(Discipline::Type disciplineType) {
    switch(disciplineType){
      case Discipline::Type::Foil: return new Weapon::Foil();
      case Discipline::Type::Sabre: return new Weapon::Foil(); // Placeholder until Sabre is implemented
      case Discipline::Type::Epee: return new Weapon::Foil(); // Placeholder until Epee is implemented
      default: return nullptr;
    }
  }
}