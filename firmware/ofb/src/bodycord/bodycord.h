#pragma once
#ifndef BODYCORD_H
#define BODYCORD_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports


class Bodycord {
  public:
    //Define a constructor
    Bodycord(uint8_t aWirePin, uint8_t bWirePin, uint8_t cWirePin);
  
    //Define public methods

    //Define public variables
    uint8_t aWirePin;
    uint8_t bWirePin;
    uint8_t cWirePin;

  protected:
    //Empty for now

  private:
    //Empty for now
};
#endif