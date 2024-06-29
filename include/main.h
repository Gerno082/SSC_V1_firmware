#ifndef __MAIN_H__
#define __MAIN_H__

////////////////////////////////////
// ---- HARDWARE DEBUG ENABLE ----//
////////////////////////////////////
// #define DEBUG_ADC
// #define DEBUG_BUTTON_PRESS_RELEASE
// #define DEBUG_CURRENT_BUTTON
// #define DEBUG_MENU_BUTTON_PRESS_RELEASE
// #define DEBUG_CURRENT_MENU_BUTTON
// #define DEBUG_ITEMS

////////////////////////////////////
// ------ WIFI DEBUG ENABLE ------//
////////////////////////////////////
#define DEBUG_WIFI
// #define DISABLE_WIFI

////////////////////////////////////
// ------ HTTP DEBUG ENABLE ------//
////////////////////////////////////
// #define DEBUG_HTTP

////////////////////////////////////
// ---- DISPLAY DEBUG ENABLE -----//
////////////////////////////////////
#define DEBUG_DISPLAY

////////////////////////////////////
// ----- STATES DEBUG ENABLE -----//
////////////////////////////////////
#define DEBUG_STATES


#define Debug Serial




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





// extern uint8_t wifi_init_done;
extern uint8_t lcd_init_done;



#endif