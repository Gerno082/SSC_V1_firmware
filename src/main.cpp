//Platform includes
#include <Arduino.h>
#include <SPI.h>



//Local includes
#include "main.h"
#include "mc_freertos.h"
#include "HAL/include/mc_button.h"
#include "HAL/include/mc_commands.h"
#include "HAL/include/mc_led.h"

#include "types.h"





//External variables







//global variables
uint8_t system_state = STATE_INIT;
// uint8_t wifi_init_done = false;
uint8_t lcd_init_done = false;







// hspi = new SPIClass(HSPI);


//define freertos object
mc_freertos rtos;
// mc_button   button = mc_button();
mc_commands cmd;
mc_led      led;






//TODO Critical features
//  TODO WIFI connect, disconnect stateflow
//  TODO Add HTTP stuff
//  TODO Add LCD stuff
//  TODO Add an "Not yet checked" button option when holding a button


//TODO Nice to haves when everything works
//  TODO add fading in/out LED's when uploading to server


void print_debug_messages();

bool button_changed = false;


void button_changed_ISR() {
  button_changed = true;
}



void setup() {

  Debug.begin(115200);

  print_debug_messages();

  pinMode(CHECK_INT_PIN, INPUT);


  delay(3000);

  led.init();


  

  // attachInterrupt(CHECK_INT_PIN, button_changed_ISR, FALLING);

  // button.init();


  rtos.init();

}

void loop() {

  if(button_changed == 1){
    Serial.print("State:");
    Serial.println(digitalRead(CHECK_INT_PIN));

    button_changed = 0;
  }


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