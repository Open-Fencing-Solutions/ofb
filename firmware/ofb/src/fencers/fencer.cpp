//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports
#include "../bouts/side.h"
#include "../disciplines/type.h"
#include "fencer.h"


// Constructor implementation
Fencer::Fencer(Discipline::Type disciplineType, Bout::Side side){
  this->side = side;

  //Get the right lame for the discipline and activate it
  this->lame = Lame::Base::getLameByDiscipline(disciplineType);
  if (this->lame != nullptr){ //Sabre doesn't have a lame
    //this->lame->Activate(side);
  }
  
  //Get the right weapon for the discipline and activate it
  this->weapon = Weapon::Base::getWeaponByDiscipline(disciplineType);
  if (this->weapon != nullptr){
    this->weapon->activate(side); //Unneeded for a weapon but this way it is consistant with a lame
  }
}

// Destructor implementation
Fencer::~Fencer(){
  //Clean-up memory of dynamicly allocated variables
  if (lame != nullptr) {
    delete lame;
    lame = nullptr;
  }
  if (weapon != nullptr) {
    delete weapon;
    weapon = nullptr;
  }
}