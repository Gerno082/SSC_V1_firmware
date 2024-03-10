#ifndef __MC_BUTTON_H__
#define __MC_BUTTON_H__


//Platform includes
#include <stdint.h>

//Local includes
#include "HAL/include/mc_log_events.h"
#include "HAL/include/mc_adc.h"



//Button params
#define SELECT_BUTTONS_COUNT    14  //Define how many rows are in the button grid
#define SELECT_BUTTONS_COLUMNS  3   //Define how many columns are in the button grid


//define how many menu buttons are available
#define MENU_BUTTONS_COUNT  5


//Button timing
#define BUTTON_POLL_RATE   1        //buttons poll rate in milliseconds
#define BUTTON_PRESS_DEBOUNCE_TIME    30    //press debounce time in milliseconds
#define BUTTON_RELEASE_DEBOUNCE_TIME  100   //release debounce time





class mc_button{

  public:
    mc_button();

    ~mc_button();

    void init();

    //Check buttons
    uint8_t get_button_pressed(uint8_t, uint16_t);
    void read_button_column(uint8_t, uint16_t analog_value);

    //Menu buttons
    uint8_t get_menu_button_pressed(uint16_t);
    void read_menu_buttons(uint16_t analog_value);

    //General button functions
    void read_all_buttons(uint32_t);
    void button_press_callback(uint8_t _row, uint8_t _column, uint8_t _button_state);



  private:

    //Define objects
    mc_adc adc;
    mc_items items;
    
    //states of individual buttons
    enum button_press_states{     ////////////////////////////////////////This should be changed, BUTTON_PRESSED and BUTTON_RELEASED is also defined in button.h
      BUTTON_PRESSED = 0,
      BUTTON_RELEASED = 1
    };

    //states of each column
    enum column_states
    {
      COLUMN_IDLE = 0,
      COLUMN_PRESSED = 1
    };

    //order of the columns int the buffer
    enum button_columns
    {
      COL1_BTN = 0,
      COL2_BTN = 1,
      COL3_BTN = 2
    };

    //define the order of the menu buttons
    enum menu_buttons{
      MENU_UP_BTN = 0,
      MENU_LEFT_BTN = 1,
      MENU_ENTER_BTN = 2,
      MENU_RIGHT_BTN = 3,
      MENU_DOWN_BTN = 4,
      MENU_OPEN_BTN = 5
    };


    //A timekeeping variable to keep track of the debounce time of each column
    unsigned long select_debounce_timer[SELECT_BUTTONS_COLUMNS] = {0};
    unsigned long menu_debounce_timer = 0;

    //timekeeping variable to time when the buttons are polled
    unsigned long button_poll_timer = 0;



    //Check button variables
    uint8_t column_btn_state[SELECT_BUTTONS_COLUMNS] = {0};                           //current state of the menu buttons columns (a button is pressed or not pressed)
    uint8_t button_pressed[SELECT_BUTTONS_COLUMNS] = {0};                             //current button that is pressed
    uint8_t last_button_pressed[SELECT_BUTTONS_COLUMNS] = {SELECT_BUTTONS_COUNT+1};   //the last button that was pressed (used to see if the current button pressed has changed)
    uint8_t last_button_pressed_2[SELECT_BUTTONS_COLUMNS] = {SELECT_BUTTONS_COUNT+1}; //the second last button that was pressed (used to store the button that was pressed after a release)
    uint16_t button_thresholds[SELECT_BUTTONS_COLUMNS][SELECT_BUTTONS_COUNT+1] = {0}; //the thresholds to decide which button is currently pressed

    //Menu button variables
    uint8_t menu_button_state = 0;                              //current state of the menu buttons columns (a button is pressed or not pressed)
    uint8_t menu_button_pressed = 0;                            //current menu button that is pressed
    uint8_t last_menu_button_pressed = MENU_BUTTONS_COUNT+1;    //the last button that was pressed (used to see if the current button pressed has changed)
    uint8_t last_menu_button_pressed_2 = MENU_BUTTONS_COUNT+1;  //the second last button that was pressed (used to store the button that was pressed after a release)
    uint16_t menu_button_thresholds[MENU_BUTTONS_COUNT+1] = {0};//the thresholds to decide which button is currently pressed



    //An estimate of the ADC raw values when each button is pressed
    uint16_t button_vals[SELECT_BUTTONS_COLUMNS][SELECT_BUTTONS_COUNT+1] = 
    {
      {//Column 1
        403/*1*/, /*0*/
        876/*2*/, 
        1277/*3*/, 
        1622/*4*/, 
        1920/*5*/, 
        2180/*6*/, 
        2400/*7*/, 
        2612/*8*/, 
        2795/*9*/, 
        2970/*10*/, 
        3130/*11*/, 
        3295/*12*/, 
        3460/*13*/, 
        3630/*14*/, 
        3805/*open*/
      },

      {//Column 2
        403/*1*/, /*0*/
        876/*2*/, 
        1277/*3*/, 
        1622/*4*/, 
        1920/*5*/, 
        2180/*6*/, 
        2400/*7*/, 
        2612/*8*/, 
        2795/*9*/, 
        2970/*10*/, 
        3130/*11*/, 
        3295/*12*/, 
        3460/*13*/, 
        3630/*14*/, 
        3805/*open*/
      },

      {//Column 3
        403/*1*/, /*0*/
        876/*2*/, 
        1277/*3*/, 
        1622/*4*/, 
        1920/*5*/, 
        2180/*6*/, 
        2400/*7*/, 
        2612/*8*/, 
        2795/*9*/, 
        2970/*10*/, 
        3130/*11*/, 
        3295/*12*/, 
        3460/*13*/, 
        3630/*14*/, 
        3805/*open*/
      }
    };


    //An estimate of the ADC raw values when each button is pressed
    uint16_t menu_button_vals[MENU_BUTTONS_COUNT+1] = 
    {
      0,      /*up*/
      1880,   /*left*/
      2560,   /*enter*/
      2912,   /*right*/
      3140,   /*down*/
      3315    /*open*/
    };

};




#endif  //__MC_BUTTON_H__