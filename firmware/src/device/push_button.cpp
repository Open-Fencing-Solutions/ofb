//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "push_button.h"

namespace Device{
  // Constructor implementation
  PushButton::PushButton(uint8_t signalPin){
    this->signalPin = signalPin
  }

  // Destructor implementation
  PushButton::~PushButton(){
    
  }

  void PushButton::Enable(){
    pinMode(this->signalPin, INPUT_PULLUP); //Use internal pull up resistors for a DEFAULT HIGH

    //Attach interrupts to the tumbler switch pins
    attachInterrupt(digitalPinToInterrupt(this->signalPin), , CHANGE);
  }
  
}