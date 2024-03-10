#include <Arduino.h>

#include "main.h"


#include "mc_freertos.h"
#include "HAL/include/mc_button.h"
#include "HAL/include/mc_commands.h"
#include "HAL/include/mc_led.h"





//define freertos object
mc_freertos rtos;
mc_button   button;
mc_commands commands;
mc_led      led;





uint8_t system_state = STATE_INIT;

uint8_t wifi_init_done = false;
uint8_t lcd_init_done = false;




void print_debug_messages();



void setup() {

  Debug.begin(115200);

  print_debug_messages();

  led.init();

  button.init();

  rtos.init();

}

void loop() {


}


void print_debug_messages(){

  #ifdef DEBUG_ADC
    Debug.println("Debug ADC enabled");
  #endif

  #ifdef DEBUG_BUTTON_PRESS_RELEASE
    Debug.println("Debug Button press/release enabled");
  #endif
  
  #ifdef DEBUG_CURRENT_BUTTON
    Debug.println("Debug Current Button enabled");
  #endif

  #ifdef DEBUG_CURRENT_MENU_BUTTON
    Debug.println("Debug Current Menu Buttons enabled");
  #endif

  #ifdef DEBUG_MENU_BUTTON_PRESS_RELEASE
    Debug.println("Debug Menu Button press/release enabled");
  #endif


  #ifdef DEBUG_ITEMS
    Debug.println("Debug Items enabled");
  #endif

}