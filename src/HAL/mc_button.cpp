//Platform includes
#include <stdint.h>
#include <Arduino.h>

//Local includes
#include "HAL/include/mc_button.h"
#include "main.h"


#include "TCA9555.h"

//External variables


//local variables


//constructor
mc_button::mc_button(uint8_t sda_pin, uint8_t scl_pin){

  _sda_pin = sda_pin;
  _scl_pin = scl_pin;

}


//destructor
mc_button::~mc_button(){

}


void mc_button::init(){


  //Init I2C bus
  _I2C_bus.begin(_sda_pin, _scl_pin, 100000);




  //Init port expanders
  BTN0_PEX_COL0.begin();
  BTN0_PEX_COL1.begin();
  //Set all pins to input
  BTN0_PEX_COL0.pinMode16(0xFFFF);
  BTN0_PEX_COL1.pinMode16(0xFFFF);


  // BTN1_PEX_COL0.begin();
  // BTN1_PEX_COL1.begin();
  //Set all pins to input
  // BTN1_PEX_COL0.pinMode16(0xFFFF);
  // BTN1_PEX_COL1.pinMode16(0xFFFF);


  // BTN2_PEX_COL0.begin();
  // BTN2_PEX_COL1.begin();
  //Set all pins to input
  // BTN2_PEX_COL0.pinMode16(0xFFFF);
  // BTN2_PEX_COL1.pinMode16(0xFFFF);


  BTN_PEX_MENU.begin();
  //Set all pins to input
  BTN_PEX_MENU.pinMode16(0xFFFF);


}





void mc_button::check_debounce(){


  // for(int column = 0; column < 3; column++){

  //   for (int button = 0; button < 11; button++){

  //     //if a button is pressed
  //     if(last_button_state[column][button] == 0){


  //       if(millis() - button_timer[column][button] >= BUTTON_DEBOUNCE_TIME){


  //         Serial.print(" Col:");
  //         Serial.print(column);
  //         Serial.print(" BTN:");
  //         Serial.print(button);
  //         Serial.println(" Pressed");


  //         last_button_state[column][button] = 2;
  //       }

  //     }




  //   }

  // }

}




int mc_button::get_button_state(uint8_t column, uint8_t button){

  int pinstate = 0;

  if(column == 0){
    if(LED_V0_button_position_map[button][1] == 0)pinstate = BTN0_PEX_COL1.read1(LED_V0_button_position_map[button][0]);
    if(LED_V0_button_position_map[button][1] == 1)pinstate = BTN0_PEX_COL0.read1(LED_V0_button_position_map[button][0]);
  }

  if(column == 1){
    if(LED_V0_button_position_map[button][1] == 0)pinstate = BTN1_PEX_COL1.read1(LED_V0_button_position_map[button][0]);
    if(LED_V0_button_position_map[button][1] == 1)pinstate = BTN1_PEX_COL0.read1(LED_V0_button_position_map[button][0]);
  }

  if(column == 2){
    if(LED_V0_button_position_map[button][1] == 0)pinstate = BTN2_PEX_COL1.read1(LED_V0_button_position_map[button][0]);
    if(LED_V0_button_position_map[button][1] == 1)pinstate = BTN2_PEX_COL0.read1(LED_V0_button_position_map[button][0]);
  }


  return pinstate;

}



void mc_button::get_button_pressed(){

  bool pinstate = 0;

  int button_num = 0;


  for(int column = 0; column < 3; column++){

      for (int button = 0; button < 22; button++){




        pinstate = get_button_state(column, button);


        if(last_button_state[column][button] != pinstate){
          last_button_state[column][button] = pinstate;

          // Serial.print(" Col:");
          // Serial.print(column);
          // Serial.print(" BTN:");
          // Serial.print(button);
          // Serial.print(" STATE:");
          // Serial.println(pinstate);

          items.log_item(button, column, pinstate);
        }



        // //If the button is released, save the state
        // if(pinstate == 1){

        //   last_button_state[column][button] = 1;

        // }




        // //If the button is pressed
        // if(pinstate == 0 &&  last_button_state[column][button] == 1){

        //   if(pinstate == 0){
        //     button_timer[column][button] = millis();
        //   }


        //   // items.log_item(bu);

        //   // Serial.print(" Col:");
        //   // Serial.print(column);
        //   // Serial.print(" SubCol:");
        //   // Serial.print(subcolumn);
        //   // Serial.print(" Row:");
        //   // Serial.print(row);
        //   // Serial.print(" State:");
        //   // Serial.println(pinstate);

        //   last_button_state[column][button] = 0;

        // }


      }

    

  }


}



void mc_button::get_menu_button_pressed(){

  for (int row = 0; row < 5; row++){

    bool pinstate = BTN2_PEX_COL0.read1(MENU_V0_button_position_map[row]);

    Serial.print(" MENU Row:");
    Serial.print(row);
    Serial.print(" State:");
    Serial.println(pinstate);

  }

}






// void mc_button::read_button_column(uint8_t _column_num, uint16_t analog_value){

//   //Make sure the column number is valid
//   if(_column_num != COL1_BTN && _column_num != COL2_BTN && _column_num != COL3_BTN){

//     #ifdef DEBUG_BUTTON_PRESS_RELEASE
//       Debug.println("Invalid button column selected");
//     #endif

//     return;
//   }

//   //Save the current button press in the array
//   button_pressed[_column_num] = get_button_pressed(_column_num, analog_value);

//   #ifdef DEBUG_CURRENT_BUTTON
//     Debug.print("  Col");
//     Debug.print(_column_num);
//     Debug.print(": ");
//     Debug.print(button_pressed[_column_num]);
//     if(_column_num == COL3_BTN)Debug.println();
//   #endif

//   //if the button changes
//   if(button_pressed[_column_num] != last_button_pressed[_column_num]){
//     select_debounce_timer[_column_num] = millis();     //Start the debounce timer
//     last_button_pressed[_column_num] = button_pressed[_column_num];   //Reset the last button pressed variable
//   }

//   //If the current button is a valid button and the debounce timer has run out
//   if(button_pressed[_column_num] <= SELECT_BUTTONS_COUNT && (millis() - select_debounce_timer[_column_num]) >= BUTTON_PRESS_DEBOUNCE_TIME && column_btn_state[_column_num] == COLUMN_IDLE){

//     //Update the variables that detects if a new button is pressed
//     last_button_pressed_2[_column_num] = button_pressed[_column_num];
//     column_btn_state[_column_num] = COLUMN_PRESSED;

//     #ifdef DEBUG_BUTTON_PRESS_RELEASE
//       Debug.print("Col");
//       Debug.print(_column_num);
//       Debug.print(": Button ");
//       Debug.print(button_pressed[_column_num]);
//       Debug.println(" Pressed");
//     #endif

//     button_press_callback(button_pressed[_column_num], _column_num, BUTTON_PRESSED);

//   }


//   //If the last button was no button and the debounce timer has run out
//   if(last_button_pressed[_column_num] > SELECT_BUTTONS_COUNT && (millis() - select_debounce_timer[_column_num]) >= BUTTON_RELEASE_DEBOUNCE_TIME && column_btn_state[_column_num] == COLUMN_PRESSED){

//     column_btn_state[_column_num] = COLUMN_IDLE;    //Update the button state

//     #ifdef DEBUG_BUTTON_PRESS_RELEASE
//       Debug.print("Col");
//       Debug.print(_column_num);
//       Debug.print(": Button ");
//       Debug.print(last_button_pressed_2[_column_num]);
//       Debug.println(" Released");
//     #endif

//     button_press_callback(button_pressed[_column_num], _column_num, BUTTON_RELEASED); //Log the button release

//   }

// }





// void mc_button::read_menu_buttons(uint16_t analog_value){


//   menu_button_pressed = get_menu_button_pressed(analog_value);

//   #ifdef DEBUG_CURRENT_MENU_BUTTON
//     if(menu_button_pressed == MENU_UP_BTN)Debug.print("UP");
//     if(menu_button_pressed == MENU_DOWN_BTN)Debug.print("DOWN");
//     if(menu_button_pressed == MENU_LEFT_BTN)Debug.print("LEFT");
//     if(menu_button_pressed == MENU_RIGHT_BTN)Debug.print("RIGHT");
//     if(menu_button_pressed == MENU_ENTER_BTN)Debug.print("ENTER");
//     if(menu_button_pressed >= MENU_BUTTONS_COUNT)Debug.print("NO");
//     Debug.println(" Menu Buttons Pressed");

//   #endif

  
//   //if the button changes
//   if(menu_button_pressed != last_menu_button_pressed){
//     menu_debounce_timer = millis();     //Start the debounce timer
//     last_menu_button_pressed = menu_button_pressed;   //Reset the last button pressed variable
//   }

//   //If the last button was a valid button and the debounce timer has run out
//   if(menu_button_pressed <= MENU_BUTTONS_COUNT && (millis() - menu_debounce_timer) >= BUTTON_PRESS_DEBOUNCE_TIME && menu_button_state == COLUMN_IDLE){

//     //Update the variables that detects if a new button is pressed
//     last_menu_button_pressed_2 = menu_button_pressed;
//     menu_button_state = COLUMN_PRESSED;

//     if(menu_button_pressed == MENU_UP_BTN)commands.run_command(commands.MENU_UP_COMMAND);
//     if(menu_button_pressed == MENU_DOWN_BTN)commands.run_command(commands.MENU_DOWN_COMMAND);
//     if(menu_button_pressed == MENU_LEFT_BTN)commands.run_command(commands.MENU_LEFT_COMMAND);
//     if(menu_button_pressed == MENU_RIGHT_BTN)commands.run_command(commands.MENU_RIGHT_COMMAND);
//     if(menu_button_pressed == MENU_ENTER_BTN)commands.run_command(commands.MENU_ENTER_COMMAND);

//     #ifdef DEBUG_MENU_BUTTON_PRESS_RELEASE
//       if(menu_button_pressed == MENU_UP_BTN)Debug.print("UP");
//       if(menu_button_pressed == MENU_DOWN_BTN)Debug.print("DOWN");
//       if(menu_button_pressed == MENU_LEFT_BTN)Debug.print("LEFT");
//       if(menu_button_pressed == MENU_RIGHT_BTN)Debug.print("RIGHT");
//       if(menu_button_pressed == MENU_ENTER_BTN)Debug.print("ENTER");
//       Debug.println(" Menu Button Pressed");
//     #endif

//   }

//   //If the last button was no button and the debounce timer has run out
//   if(last_menu_button_pressed > MENU_BUTTONS_COUNT && (millis() - menu_debounce_timer) >= BUTTON_RELEASE_DEBOUNCE_TIME && menu_button_state == COLUMN_PRESSED){

//     menu_button_state = COLUMN_IDLE;      //Update the button state

//     #ifdef DEBUG_MENU_BUTTON_PRESS_RELEASE
//       if(last_menu_button_pressed_2 == MENU_UP_BTN)Debug.print("UP");
//       if(last_menu_button_pressed_2 == MENU_DOWN_BTN)Debug.print("DOWN");
//       if(last_menu_button_pressed_2 == MENU_LEFT_BTN)Debug.print("LEFT");
//       if(last_menu_button_pressed_2 == MENU_RIGHT_BTN)Debug.print("RIGHT");
//       if(last_menu_button_pressed_2 == MENU_ENTER_BTN)Debug.print("ENTER");
//       Debug.println(" Menu Button Released");
//     #endif
    
//     //Button release
//   }

// }






// //Poll all the columns at a certain inteval
// void mc_button::read_all_buttons(uint32_t _poll_rate){

// }


// void mc_button::button_press_callback(uint8_t _row, uint8_t _column, uint8_t _button_state){
//   items.log_item(_row, _column, _button_state);
// }
