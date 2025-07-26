// Built-in Imports
#include <Arduino.h>

// Common imports

// Environment configuration import
#include "environment.h"

//Project imports
#include "device/discipline_selector.h"
#include "device/mode_selector.h"
#include "bouts/bout.h"

// Module variables
//Device::DisciplineSelector disciplineSelector(Environment::DISCIPLINE_SELECTOR_PINS); //Initialize DisciplineSelector
Device::ModeSelector modeSelector(Environment::MODE_SELECTOR_PINS); //Initialize ModeSelector
//Device::SignalSelector signalSelector(Environment::MODE_SELECTOR_PINS); //Initialize SignalSelector

Bout::Bout bout; //Create a bout.. This will also be (ab)ussed for trainingssessions.

void setup() {
  // Intialize a serial connection for debugging
  Serial.begin(115200);

  modeSelector.enable();
  
}

void loop() {

  // Only handle low prority interupts when there is not an hit going
  if (bout.state != Bout::State::HIT){
    //disciplineSelector.handleInterrupts(); //Checks if interrupt is triggered and if so update the discipline
    modeSelector.handleInterrupts(); //Checks if interrupt is triggered and if so update the device mode
    //signalSelector.handleInterrupts(); //Checks if interrupt is triggered and if so update the signal mode
  }

  // Now handle anything bout related if we are not in lockout mode
  // bout.handleState();
  delay(1000);
}