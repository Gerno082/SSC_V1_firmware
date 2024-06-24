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

#define LED_COUNT  22

#define LED1_PIN  22
#define LED2_PIN  21
#define LED3_PIN  19

#define LED_COL1_BUFFERS_COUNT  0
#define LED_COL2_BUFFERS_COUNT  1
#define LED_COL3_BUFFERS_COUNT  2










class mc_led{

    public:
        mc_led();

        ~mc_led();

        void init();

        void update_all_leds(uint8_t red, uint8_t green, uint8_t blue);

        void set_LED_colour(uint8_t _row, uint8_t _col, uint8_t _red, uint8_t _green, uint8_t _blue);

        void set_start_LEDs();

        //Columns enumeration
        enum led_columns{
            LED_COL1 = 0,
            LED_COL2 = 1,
            LED_COL3 = 2
        };


    //This should not be here, should only be in items

        enum item_states{
      UNCHECKED = 0,
      CHECKED = 1,
      CHECKED_YES = 2,
      CHECKED_NA = 3
    };





    enum item_button_states{
      BUTTON_PRESSED = 0,
      BUTTON_RELEASED = 1
    };

    enum item_types{
      ITEM_TYPE_DUAL_STATE = 0,
      ITEM_TYPE_TRI_STATE = 1,
      ITEM_TYPE_QUAD_STATE = 2
    };


        
    typedef struct{
      uint8_t type;
      uint8_t column;
      uint8_t state;
      uint8_t btn[3];
      uint8_t command[2];
    }  item_map_layer;


    item_map_layer ITEMS[23] = {
      //Column 1 buttons (8 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    0        /*Buttons*/},    //Identity
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    2        /*Buttons*/},    //Procedure
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    4        /*Buttons*/},    //site
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    6        /*Buttons*/},    //consent
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    8        /*Buttons*/},    //allergies
      { ITEM_TYPE_QUAD_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {10,11,12}/*Buttons*/},    //side checked
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {14,15}   /*Buttons*/},    //site marked
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {20,21}   /*Buttons*/},    //blood on standby, 7

      //Column 2 buttons (8 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    0        /*Buttons*/},    //Introduce team members
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    4        /*Buttons*/},    //Patient identity
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    6        /*Buttons*/},    //Procedure
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    8        /*Buttons*/},    //Site
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    10       /*Buttons*/},    //Sterility of instruments
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {12,13}  /*Buttons*/},    //Confirm any implants
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {16,17}  /*Buttons*/},    //anticipated critical events
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {20,21}  /*Buttons*/},    //Antibiotic prophylaxis, 15

      //Column 3 buttons (7 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    0        /*Buttons*/},    //Surgeon confirm procedure name
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {4,5}    /*Buttons*/},    //swabs
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {6,7}    /*Buttons*/},    //sharps
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {8,9}    /*Buttons*/},    //isntruments counted
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {12,13}  /*Buttons*/},    //Specimen is labelled
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {16,17}  /*Buttons*/},    //equipment issues reported
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {16,17}  /*Buttons*/}     //Log event button, 22
    };




        int8_t LED_V0_WS2811_position_map[22] = 
        {
            /*00*/0,
            /*01*/21,
            /*02*/1,
            /*03*/20,
            /*04*/2,
            /*05*/19,
            /*06*/3,
            /*07*/18,
            /*08*/4,
            /*09*/17,
            /*10*/5,
            /*11*/16,
            /*12*/6,
            /*13*/15,
            /*14*/7,
            /*15*/14,
            /*16*/8,
            /*17*/13,
            /*18*/9,
            /*19*/12,
            /*20*/10,
            /*21*/11,
        };


    private:
        Adafruit_NeoPixel COL1_LED;
        Adafruit_NeoPixel COL2_LED;
        Adafruit_NeoPixel COL3_LED;

};



#endif  //__MC_LED_H__