// Built-in Imports
#include <Arduino.h>

// Environment configuration import
#include "environment.h"

//Project imports
#include "device/discipline_selector.h"
#include "bouts/bout.h"
#include "disciplines/type.h"

// Module variables
Device::DisciplineSelector disciplineSelector(environment::DISCIPLINE_SELECTOR_PINS); //Initialize DisciplineSelector
Discipline::Type selectedDiscipline; //Because the disciplineSelector has not been used (yet), initialize none
Bout::Bout* bout = nullptr; //Create a bout.. This will also be (ab)ussed for trainingssessions.

void setup() {
  // Intialize a serial connection for debugging
  Serial.begin(115200);

  // Get a discipline from the selector and initialize a bout
  selectedDiscipline = disciplineSelector.getSelectedDiscipline();
  bout = new Bout::Bout(selectedDiscipline);
}

void loop() {
  if (bout == nullptr){
    return;
  }

  for (uint8_t i = 0; i < sizeof(bout->fencers) / sizeof(Fencer); i++) {
      Serial.println(bout->fencers[i].weapon->isDepressed());
  }

  delay(1000);
}