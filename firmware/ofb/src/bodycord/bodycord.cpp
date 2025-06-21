//Built-in Imports
#include <Arduino.h>

//Common imports

//Class header import
#include "bodycord.h"

//Custom imports


// Constructor implementation
Bodycord::Bodycord(uint8_t aWirePin, uint8_t bWirePin, uint8_t cWirePin){
  this->aWirePin = aWirePin;
  this->bWirePin = bWirePin;
  this->cWirePin = cWirePin;
}