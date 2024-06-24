#ifndef __MC_BUTTON_H__
#define __MC_BUTTON_H__


//Platform includes
#include <stdint.h>

//Local includes
#include "HAL/include/mc_log_events.h"

#include "TCA9555.h"

#include "mc_log_events.h"


//Button params
// #define SELECT_BUTTONS_COUNT    14  //Define how many rows are in the button grid
// #define SELECT_BUTTONS_COLUMNS  3   //Define how many columns are in the button grid


// //define how many menu buttons are available
// #define MENU_BUTTONS_COUNT  5


// //Button timing
// #define BUTTON_POLL_RATE   1        //buttons poll rate in milliseconds
// #define BUTTON_PRESS_DEBOUNCE_TIME    30    //press debounce time in milliseconds
// #define BUTTON_RELEASE_DEBOUNCE_TIME  100   //release debounce time



#define NO_BTN -1



#define BUTTON_DEBOUNCE_TIME    50

//define port expanders objects

//Address = 0 1 0 0 A2 A1 A0




class mc_button{

  public:
    mc_button(uint8_t, uint8_t);

    ~mc_button();

    void init();



    void check_debounce();
  


    int get_button_state(uint8_t, uint8_t);


    //Check buttons
    void get_button_pressed();
    // void read_button_column(uint8_t, uint16_t analog_value);

    //Menu buttons
    void get_menu_button_pressed();
    // void read_menu_buttons(uint16_t analog_value);

    // //General button functions
    // void read_all_buttons(uint32_t);
    // void button_press_callback(uint8_t _row, uint8_t _column, uint8_t _button_state);



  private:


    uint8_t _sda_pin;
    uint8_t _scl_pin;  
    
    TwoWire _I2C_bus = TwoWire(0);

    TCA9555 BTN0_PEX_COL0 = TCA9555(0x20, &_I2C_bus);   // A2 A1 A0 = 0 0 0
    TCA9555 BTN0_PEX_COL1 = TCA9555(0x24, &_I2C_bus);   // A2 A1 A0 = 1 0 0

    TCA9555 BTN1_PEX_COL0 = TCA9555(0x22, &_I2C_bus);   // A2 A1 A0 = 0 1 0   
    TCA9555 BTN1_PEX_COL1 = TCA9555(0x26, &_I2C_bus);   // A2 A1 A0 = 1 1 0

    TCA9555 BTN2_PEX_COL0 = TCA9555(0x21, &_I2C_bus);   // A2 A1 A0 = 0 0 1   
    TCA9555 BTN2_PEX_COL1 = TCA9555(0x25, &_I2C_bus);   // A2 A1 A0 = 1 0 1

    TCA9555 BTN_PEX_MENU = TCA9555(0x27, &_I2C_bus);    // A2 A1 A2 = 1 1 1




    //Define objects
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




    //define the order of the menu buttons
    enum menu_buttons{
      MENU_UP_BTN = 0,
      MENU_LEFT_BTN = 1,
      MENU_ENTER_BTN = 2,
      MENU_RIGHT_BTN = 3,
      MENU_DOWN_BTN = 4,
      MENU_OPEN_BTN = 5
    };


    // //A timekeeping variable to keep track of the debounce time of each column
    // unsigned long select_debounce_timer[SELECT_BUTTONS_COLUMNS] = {0};
    // unsigned long menu_debounce_timer = 0;

    // //timekeeping variable to time when the buttons are polled
    // unsigned long button_poll_timer = 0;



    // //Check button variables
    // uint8_t column_btn_state[SELECT_BUTTONS_COLUMNS] = {0};                           //current state of the menu buttons columns (a button is pressed or not pressed)
    // uint8_t button_pressed[SELECT_BUTTONS_COLUMNS] = {0};                             //current button that is pressed
    // uint8_t last_button_pressed[SELECT_BUTTONS_COLUMNS] = {SELECT_BUTTONS_COUNT+1};   //the last button that was pressed (used to see if the current button pressed has changed)
    // uint8_t last_button_pressed_2[SELECT_BUTTONS_COLUMNS] = {SELECT_BUTTONS_COUNT+1}; //the second last button that was pressed (used to store the button that was pressed after a release)
    // uint16_t button_thresholds[SELECT_BUTTONS_COLUMNS][SELECT_BUTTONS_COUNT+1] = {0}; //the thresholds to decide which button is currently pressed

    // //Menu button variables
    // uint8_t menu_button_state = 0;                              //current state of the menu buttons columns (a button is pressed or not pressed)
    // uint8_t menu_button_pressed = 0;                            //current menu button that is pressed
    // uint8_t last_menu_button_pressed = MENU_BUTTONS_COUNT+1;    //the last button that was pressed (used to see if the current button pressed has changed)
    // uint8_t last_menu_button_pressed_2 = MENU_BUTTONS_COUNT+1;  //the second last button that was pressed (used to store the button that was pressed after a release)
    // uint16_t menu_button_thresholds[MENU_BUTTONS_COUNT+1] = {0};//the thresholds to decide which button is currently pressed



    // uint8_t last_button_state[3][2][11] = {0};    //3x Main columns, 2x subcolumns, 11 rows

    uint8_t last_button_state[3][22] = {0};    //3x Main columns, 2x subcolumns, 11 rows

    // uint32_t button_timer[3][2][11] = {0};

    uint32_t button_timer[3][22] = {0};

    // int8_t LED_V0_button_position_map[2][16] = 
    // {
    //   {//Column 0
    //     /*00*/5,
    //     /*01*/4,
    //     /*02*/3, 
    //     /*03*/2, 
    //     /*04*/1, 
    //     /*05*/0, 
    //     /*06*/11, 
    //     /*07*/12, 
    //     /*08*/13, 
    //     /*09*/14, 
    //     /*10*/15
    //   },

    //   {//Column 1
    //     /*00*/0,
    //     /*01*/1,
    //     /*02*/2, 
    //     /*03*/3, 
    //     /*04*/4, 
    //     /*05*/5, 
    //     /*06*/15, 
    //     /*07*/14, 
    //     /*08*/13, 
    //     /*09*/12, 
    //     /*10*/11
    //   }

    // };




    int8_t LED_V0_button_position_map[22][2] = 
    {
      /*00*/{5 /*Pin*/, 0/*Port expander*/},
      /*01*/{0 /*Pin*/, 1/*Port expander*/},
      /*02*/{4 /*Pin*/, 0/*Port expander*/},
      /*03*/{1 /*Pin*/, 1/*Port expander*/},
      /*04*/{3 /*Pin*/, 0/*Port expander*/},
      /*05*/{2 /*Pin*/, 1/*Port expander*/},
      /*06*/{2 /*Pin*/, 0/*Port expander*/},
      /*07*/{3 /*Pin*/, 1/*Port expander*/},
      /*08*/{1 /*Pin*/, 0/*Port expander*/},
      /*09*/{4 /*Pin*/, 1/*Port expander*/},
      /*10*/{0 /*Pin*/, 0/*Port expander*/},
      /*11*/{5 /*Pin*/, 1/*Port expander*/},
      /*12*/{11/*Pin*/, 0/*Port expander*/},
      /*13*/{15/*Pin*/, 1/*Port expander*/},
      /*14*/{12/*Pin*/, 0/*Port expander*/},
      /*15*/{14/*Pin*/, 1/*Port expander*/},
      /*16*/{13/*Pin*/, 0/*Port expander*/},
      /*17*/{13/*Pin*/, 1/*Port expander*/},
      /*18*/{14/*Pin*/, 0/*Port expander*/},
      /*19*/{12/*Pin*/, 1/*Port expander*/},
      /*20*/{15/*Pin*/, 0/*Port expander*/},
      /*21*/{11/*Pin*/, 1/*Port expander*/},
    };












    uint8_t MENU_V0_button_position_map[5] = 
    {
      /*00*/0,
      /*01*/1,
      /*02*/2, 
      /*03*/3, 
      /*04*/4
    };


    uint8_t MENU_V0_WS2811_position_map[5] = 
    {
      /*00*/0,
      /*01*/1,
      /*02*/2, 
      /*03*/3, 
      /*04*/4
    };





};




#endif  //__MC_BUTTON_H__