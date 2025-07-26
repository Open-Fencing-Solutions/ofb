//Built-in Imports
#include <Arduino.h>
#include "esp_sleep.h"

//Common imports

//Project imports
#include "wake_up_button.h"

namespace Device{
  // Constructor implementation
  WakeUpButton::WakeUpButton(uint8_t signalPin){
    this->signalPin = signalPin;
  }
  
  WakeUpButton::~WakeUpButton(){
    this->disable();
  }

  void WakeUpButton::enable(){
    pinMode(this->signalPin, INPUT_PULLUP); //Use internal pull up resistors for a DEFAULT HIGH
    esp_sleep_enable_ext0_wakeup(static_cast<gpio_num_t>(signalPin), 0); // Wake up when pin goes LOW 
  }

  void WakeUpButton::disable(){
    esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_EXT0);

    //Revert the pins to default INPUT mode
    pinMode(this->signalPin, INPUT); 
  }
}