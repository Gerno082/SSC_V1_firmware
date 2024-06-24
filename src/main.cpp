//Platform includes
#include <Arduino.h>

//Local includes
#include "main.h"
#include "mc_freertos.h"
#include "HAL/include/mc_button.h"
#include "HAL/include/mc_commands.h"
#include "HAL/include/mc_led.h"

#include "types.h"

//External variables







#define MENU_INT_PIN    34
#define MENU_EXTRA_PIN  35
#define MENU_LED_PIN    27

#define DISP_BUSY_PIN   32
#define DISP_RST_PIN    33
#define DISP_DC_PIN     25
#define DISP_CS_PIN     26

#define SPI_SCK_PIN     14
#define SPI_MISO_PIN    12
#define SPI_MOSI_PIN    13

#define CHECK_INT_PIN   23
#define LED1_PIN        22
#define LED2_PIN        21
#define LED3_PIN        19

#define EXT_INT_PIN     18
#define EXT_CS_PIN      5

#define SD_CS_PIN       4

#define POWERGOOD_PIN   2

#define BUZZER_PIN      15




//global variables
uint8_t system_state = STATE_INIT;
uint8_t wifi_init_done = false;
uint8_t lcd_init_done = false;


//define freertos object
mc_freertos rtos;
// mc_button   button = mc_button();
mc_commands commands;
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