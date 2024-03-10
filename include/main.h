#ifndef __MAIN_H__
#define __MAIN_H__



// #define DEBUG_ADC
// #define DEBUG_BUTTON_PRESS_RELEASE
// #define DEBUG_CURRENT_BUTTON
// #define DEBUG_MENU_BUTTON_PRESS_RELEASE
// #define DEBUG_CURRENT_MENU_BUTTON
#define DEBUG_ITEMS

#define Debug Serial




extern uint8_t wifi_init_done;
extern uint8_t lcd_init_done;


enum mc_system_states{
  STATE_INIT = 0,
  STATE_WAITING_FOR_WIFI = 1,
  STATE_IDLE = 2,
  STATE_SURGERY_BUSY = 3
};



#endif