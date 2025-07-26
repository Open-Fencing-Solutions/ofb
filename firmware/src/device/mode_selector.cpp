//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "mode_selector.h"
#include "../bouts/bout.h"

//Setup globally accessible pointers
extern Bout::Bout bout;

//Need to set the activeInstance pointer to a nullptr so that the compiler reserves space for it.
Device::ModeSelector* Device::ModeSelector::activeInstance = nullptr;

namespace Device{
  // Static interrupt handler for the switch
  void IRAM_ATTR ModeSelector::interruptHandler(){
    if (ModeSelector::activeInstance) {
      ModeSelector::activeInstance->interruptTriggered = true;
    }
  }

  // Constructor implementation
  ModeSelector::ModeSelector(const uint8_t selectorPins[2]){
    //Set variables for this class instance
    this->topPin = selectorPins[0];
    this->bottomPin = selectorPins[1];

    //Set a pointer on the static class to this instance
    //This is the only way to find this instance from the main loop
    ModeSelector::activeInstance = this;
  }

  // Destructor implementation
  ModeSelector::~ModeSelector(){
    //Disable the interrupts for this switch
    this->disable();

    //Remove this instance pointer from the static class
    ModeSelector::activeInstance = nullptr;
  }

  void ModeSelector::enable(){
    pinMode(topPin, INPUT_PULLUP); //Use internal pull up resistors for a DEFAULT HIGH
    pinMode(bottomPin, INPUT_PULLUP); //Use internal pull up resistors for a DEFAULT HIGH

    //Attach interrupts to the tumbler switch pins
    attachInterrupt(digitalPinToInterrupt(this->topPin), Device::ModeSelector::interruptHandler, CHANGE);
    attachInterrupt(digitalPinToInterrupt(this->bottomPin), Device::ModeSelector::interruptHandler, CHANGE);

    //The procedure for a interrupt triggered is the same as initialization
    //So lets abuse the handleInterrupts method
    this->interruptTriggered = true;
  }

  void ModeSelector::disable(){
    //Detach the interupts from the switch pins
    detachInterrupt(digitalPinToInterrupt(this->topPin));
    detachInterrupt(digitalPinToInterrupt(this->bottomPin));

    //Revert the pins to default INPUT mode
    pinMode(topPin, INPUT); 
    pinMode(bottomPin, INPUT);
  }

  Device::Mode ModeSelector::getSelectedMode(){
    //Read the pin values for the switch
    uint8_t switchPinReadings = (digitalRead(topPin) << 1) | digitalRead(bottomPin);
    
    //Switch states based on a 3 state tumbler switch
    //This wil output 0, 1, 2 based on the pins being activated by the switch. This is the index number for the Enum
    //1 0 Top pin activated - will translate to Enum index 0
    //0 0 No pin activated - will translate to Enum index 1
    //0 1 Bottom pin activated - will translate to Enum index 2
    //1 1 Both pins activated (impossible) - will translate to Enum index 2
    uint8_t switchIndex = (switchPinReadings == 0b10) ? 0 : (switchPinReadings == 0b00) ? 1 : (switchPinReadings == 0b01) ? 2 : 2;

    //Get a mode from the Enum based on the index
    Device::Mode selectedMode = static_cast<Device::Mode>(switchIndex);

    Serial.println(static_cast<int>(selectedMode));
    
    return selectedMode;
  }

  void ModeSelector::handleInterrupts(){
    if (this->interruptTriggered != true){
      //Interrupt flag was not set, so early return.
      return;
    }

    //Get the mode that is selected
    Device::Mode selectedMode = ModeSelector::getSelectedMode();

    //Set the mode on the active bout
    bout.mode = selectedMode;

    //Interrupt handler finshed, so remove the interrupt flag
    this->interruptTriggered = false;
  }
}