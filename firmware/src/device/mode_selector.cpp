//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "mode_selector.h"

//Set the activeInstance to a nullptr.


namespace Device{
  //Need to set the activeInstance pointer to a nullptr so that the compiler reserves memory for it.
  ModeSelector* Device::ModeSelector::activeInstance = nullptr;

  // Static interrupt handler for the switch
  void IRAM_ATTR ModeSelector::interruptHandler(){
    ModeSelector::activeInstance->interruptTriggered = true;
  }

  // Constructor implementation
  ModeSelector::ModeSelector(const uint8_t selectorPins[2]){
    //Set variables for this class instance
    this->topPin = selectorPins[0];
    this->bottomPin = selectorPins[1];

    //Attach interrupts to the tumbler switch pins
    attachInterrupt(digitalPinToInterrupt(this->topPin), Device::ModeSelector::interruptHandler, CHANGE);
    attachInterrupt(digitalPinToInterrupt(this->bottomPin), Device::ModeSelector::interruptHandler, CHANGE);

    //Set a pointer on the static class to this instance
    //This is the only way to find this instance from the main loop
    ModeSelector::activeInstance = this;

    //The procedure for a interrupt triggered is the same as initialization
    //So lets abuse the handleInterrupts method
    this->interruptTriggered = true;
  }

  // Destructor implementation
  ModeSelector::~ModeSelector(){
    //Remove this instance pointer from the static class
    ModeSelector::activeInstance = nullptr;
  }

  Device::Mode ModeSelector::getSelectedMode(){
    //Switches states based on a 3 state tumbler switch
    //1 0 Top pin activated - will translate to Enum index 0
    //0 0 No pin activated - will translate to Enum index 1
    //0 1 Bottom pin activated - will translate to Enum index 2

    uint8_t switchPinReadings = (digitalRead(topPin) << 1) | digitalRead(bottomPin); //Read the state of the switch
    uint8_t switchPosition = (switchPinReadings == 0b10) ? 0 : (switchPinReadings == 0b00) ? 1 : 2; //This wil output 0, 1, 2 based on the pins being activated by the switch

    Device::Mode selectedMode = static_cast<Device::Mode>(switchPosition);
    
    return selectedMode;
  }

  void ModeSelector::handleInterrupts(){
    //Get the mode that is selected
    Device::Mode selectedMode = ModeSelector::getSelectedMode();
    
    //Set the mode 
  }
}