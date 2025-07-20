// Built-in Imports
#include <Arduino.h>

// Environment configuration import
#include "environment.h"

//Project imports
#include "device/discipline_selector.h"
#include "device/mode_selector.h"
#include "disciplines/type.h"
#include "bouts/bout.h"

// Module variables
Device::DisciplineSelector disciplineSelector(Environment::DISCIPLINE_SELECTOR_PINS); //Initialize DisciplineSelector
Device::ModeSelector modeSelector(Environment::MODE_SELECTOR_PINS); //Initialize ModeSelector
Discipline::Type selectedDiscipline; //Because the disciplineSelector has not been used (yet), initialize none
Bout::Bout* bout = nullptr; //Create a bout.. This will also be (ab)ussed for trainingssessions.

void setup() {
  // Intialize a serial connection for debugging
  Serial.begin(115200);

  // Get a discipline from the selector and initialize a bout
  selectedDiscipline = disciplineSelector.getSelectedDiscipline();
  bout = new Bout::Bout(selectedDiscipline);

  //These have not been changed but this will make sure the bout is initialized correctly on the first loop itteration
  disciplineSelector.interruptTriggered = true
  modeSelector.interruptTriggered = true
}

void loop() {

  // Only handle low prority interupts when there is not an hit going on and the device is not initializing
  if (bout->state != Bout::State::INIT && bout->state != Bout::State::HIT){
    disciplineSelector.handleInterrupts(); //Checks if interrupt is triggered and if so update the discipline
    modeSelector.handleInterrupts(); //Checks if interrupt is triggered and if so update the bout
  }


  // Now handle anything bout related if we are not in lockout mode
  bout.handleState();


  delay(1000);
}