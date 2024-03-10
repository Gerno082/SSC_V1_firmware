#include "HAL/include/mc_led.h"



mc_led::mc_led():
  #ifdef USING_DEV_LED_BOARD
    COL1_LED(LED_COUNT+LED_COL1_BUFFERS_COUNT, LED1_PIN, NEO_GRB + NEO_KHZ800),
    COL2_LED(LED_COUNT+LED_COL2_BUFFERS_COUNT, LED2_PIN, NEO_GRB + NEO_KHZ800),
    COL3_LED(LED_COUNT+LED_COL3_BUFFERS_COUNT, LED3_PIN, NEO_GRB + NEO_KHZ800)
  #else
    COL1_LED(LED_COUNT+LED_COL1_BUFFERS_COUNT, LED1_PIN, NEO_RGB + NEO_KHZ800),
    COL2_LED(LED_COUNT+LED_COL2_BUFFERS_COUNT, LED2_PIN, NEO_RGB + NEO_KHZ800),
    COL3_LED(LED_COUNT+LED_COL3_BUFFERS_COUNT, LED3_PIN, NEO_RGB + NEO_KHZ800)
  #endif
{
}


mc_led::~mc_led(){

}


//Init all the LEDs and set them to red
void mc_led::init(){

  COL1_LED.begin(); // INITIALIZE Neopixel object
  COL2_LED.begin();
  COL3_LED.begin();

  // update_all_leds(0, 0, LED_BRIGHTNESS);

  update_all_leds(LED_BRIGHTNESS, 0, 0);
  
}


// Update all LEDs
void mc_led::update_all_leds(uint8_t red, uint8_t green, uint8_t blue){

  for(int i = LED_COL1_BUFFERS_COUNT; i < LED_COUNT+LED_COL1_BUFFERS_COUNT; i++)COL1_LED.setPixelColor(i, COL1_LED.Color(red, green, blue));
  COL1_LED.show();   // Send the updated pixel colors to the hardware.

  for(int i = LED_COL1_BUFFERS_COUNT; i < LED_COUNT+LED_COL2_BUFFERS_COUNT; i++)COL2_LED.setPixelColor(i, COL2_LED.Color(red, green, blue));
  COL2_LED.show();   // Send the updated pixel colors to the hardware.

  for(int i = LED_COL3_BUFFERS_COUNT; i < LED_COUNT+LED_COL3_BUFFERS_COUNT; i++)COL3_LED.setPixelColor(i, COL3_LED.Color(red, green, blue));
  COL3_LED.show();   // Send the updated pixel colors to the hardware.

}



//Set the LED colour at a specific row and column
void mc_led::set_LED_colour(uint8_t _row, uint8_t _col, uint8_t _red, uint8_t _green, uint8_t _blue){

  if(_col == LED_COL1){

    COL1_LED.setPixelColor(_row+LED_COL1_BUFFERS_COUNT, COL1_LED.Color(_red, _green, _blue));
    COL1_LED.show();

  }else if(_col == LED_COL2){

    COL2_LED.setPixelColor(_row+LED_COL2_BUFFERS_COUNT, COL2_LED.Color(_red, _green, _blue));
    COL2_LED.show();

  }else if(_col == LED_COL3){

    COL3_LED.setPixelColor(_row+LED_COL3_BUFFERS_COUNT, COL3_LED.Color(_red, _green, _blue));
    COL3_LED.show();

  }

}
