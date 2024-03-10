#ifndef __MC_LED_H__
#define __MC_LED_H__

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>




// Variables
/*
enum led_states
{
    ITEM_UNCHECKED = 0,
    ITEM_CHECKED = 1    
};*/





 


//Store the current state of the LED's (checked(1) or unchecked(0))
// bool LED_state[3][LED_COUNT] = {0};





//LED params
#define LED_BRIGHTNESS    255   //0 - 255 value
// uint8_t LED_BRIGHTNESS_external = LED_BRIGHTNESS;

//uncomment if the dev board is used
// #define USING_DEV_LED_BOARD

#define LED_COUNT  14 

#define LED1_PIN  21
#define LED2_PIN  19
#define LED3_PIN  18

#define LED_COL1_BUFFERS_COUNT  0
#define LED_COL2_BUFFERS_COUNT  0
#define LED_COL3_BUFFERS_COUNT  0











class mc_led{

    public:
        mc_led();

        ~mc_led();

        void init();

        void update_all_leds(uint8_t red, uint8_t green, uint8_t blue);

        void set_LED_colour(uint8_t _row, uint8_t _col, uint8_t _red, uint8_t _green, uint8_t _blue);

        //Columns enumeration
        enum led_columns{
            LED_COL1 = 0,
            LED_COL2 = 1,
            LED_COL3 = 2
        };

    private:
        Adafruit_NeoPixel COL1_LED;
        Adafruit_NeoPixel COL2_LED;
        Adafruit_NeoPixel COL3_LED;

};



#endif  //__MC_LED_H__