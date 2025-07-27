//Built-in Imports
#include <Arduino.h>

//Common imports

//Project imports
#include "signal_mode_selector.h"
#include "../bouts/bout.h"

//Setup globally accessible pointers
extern Bout::Bout bout;

//Need to set the activeInstance pointer to a nullptr so that the compiler reserves space for it.
Device::SignalModeSelector* Device::SignalModeSelector::activeInstance = nullptr;

namespace Device{
  // Static interrupt handler for the switch
  void IRAM_ATTR SignalModeSelector::interruptHandler(){
    if (SignalModeSelector::activeInstance) {
      SignalModeSelector::activeInstance->interruptTriggered = true;
    }
  }

  // Constructor implementation
  SignalModeSelector::SignalModeSelector(const uint8_t selectorPins[2]){
    //Set variables for this class instance
    this->topPin = selectorPins[0];
    this->bottomPin = selectorPins[1];

    //Set a pointer on the static class to this instance
    //This is the only way to find this instance from the main loop
    SignalModeSelector::activeInstance = this;
  }

  // Destructor implementation
  SignalModeSelector::~SignalModeSelector(){
    //Disable the interrupts for this switch
    this->disable();

    //Remove this instance pointer from the static class
    SignalModeSelector::activeInstance = nullptr;
  }

  void SignalModeSelector::enable(){
    pinMode(topPin, INPUT_PULLUP); //Use internal pull up resistors for a DEFAULT HIGH
    pinMode(bottomPin, INPUT_PULLUP); //Use internal pull up resistors for a DEFAULT HIGH

    //Attach interrupts to the tumbler switch pins
    attachInterrupt(digitalPinToInterrupt(this->topPin), Device::SignalModeSelector::interruptHandler, CHANGE);
    attachInterrupt(digitalPinToInterrupt(this->bottomPin), Device::SignalModeSelector::interruptHandler, CHANGE);

    //The procedure for a interrupt triggered is the same as initialization
    //So lets abuse the handleInterrupts method
    this->interruptTriggered = true;
  }

  void SignalModeSelector::disable(){
    //Detach the interupts from the switch pins
    detachInterrupt(digitalPinToInterrupt(this->topPin));
    detachInterrupt(digitalPinToInterrupt(this->bottomPin));

    //Revert the pins to default INPUT mode
    pinMode(this->topPin, INPUT); 
    pinMode(this->bottomPin, INPUT);
  }

  Device::SignalMode SignalModeSelector::getSelectedSignalMode(){
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
    Device::SignalMode selectedMode = static_cast<Device::SignalMode>(switchIndex);

    Serial.println(static_cast<int>(selectedMode));
    
    return selectedMode;
  }

  void SignalModeSelector::handleInterrupts(){
    if (this->interruptTriggered != true){
      //Interrupt flag was not set, so early return.
      return;
    }

    //Get the mode that is selected
    Device::SignalMode selectedMode = SignalModeSelector::getSelectedSignalMode();

    //Set the mode on the active bout
    bout.signalMode = selectedMode;

    //Interrupt handler finshed, so remove the interrupt flag
    this->interruptTriggered = false;
  }
}