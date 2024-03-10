
#include <stdint.h>
#include <Arduino.h>

#include "HAL/include/mc_button.h"

#include "main.h"

//constructor
mc_button::mc_button(){

}


//destructor
mc_button::~mc_button(){

}


void mc_button::init(){

  //setup the adc
  adc.init();

  //Fill the menu buttons buffer
  for(int i = 0; i < MENU_BUTTONS_COUNT+1; i++){
    if(i == 0){
      menu_button_thresholds[i] = ( menu_button_vals[i] )/2;
    }else{
      menu_button_thresholds[i] = (menu_button_vals[i-1] + menu_button_vals[i])/2;
    }

  }

  //main buttons
  for(int i = 0; i < SELECT_BUTTONS_COUNT+1; i++){
    for(int j = 0; j < SELECT_BUTTONS_COLUMNS; j++){
      if(i == 0){
        button_thresholds[j][i] = ( button_vals[j][i] )/2;
      }else{
        button_thresholds[j][i] = (button_vals[j][i-1] + button_vals[j][i])/2;
      }
    }
  }

}





uint8_t mc_button::get_button_pressed(uint8_t _column_num, uint16_t analog_value){


  for(int i = 0; i < SELECT_BUTTONS_COUNT+1; i++){

    if(analog_value >= button_thresholds[_column_num][i] && analog_value < button_thresholds[_column_num][i+1]){
      return (i+1);
    }

  }

  //If the code made it to here, then no buttons are pressed to we return open circuit (which is the last button+1)
  return SELECT_BUTTONS_COUNT+1;

}



uint8_t mc_button::get_menu_button_pressed(uint16_t analog_value){


  for(int i = 0; i < MENU_BUTTONS_COUNT+1; i++){

    if(analog_value >= menu_button_thresholds[i] && analog_value < menu_button_thresholds[i+1]){
      return (i+1);
    }
  }

  //If the code made it to here, then no buttons are pressed to we return open circuit (which is the last button+1)
  return 6;

}






void mc_button::read_button_column(uint8_t _column_num, uint16_t analog_value){

  //Make sure the column number is valid
  if(_column_num != COL1_BTN && _column_num != COL2_BTN && _column_num != COL3_BTN){

    #ifdef DEBUG_BUTTON_PRESS_RELEASE
      Debug.println("Invalid button column selected");
    #endif

    return;
  }

  //Save the current button press in the array
  button_pressed[_column_num] = get_button_pressed(_column_num, analog_value);

  #ifdef DEBUG_CURRENT_BUTTON
    Debug.print("  Col");
    Debug.print(_column_num);
    Debug.print(": ");
    Debug.print(button_pressed[_column_num]);
    if(_column_num == COL3_BTN)Debug.println();
  #endif

  //if the button changes
  if(button_pressed[_column_num] != last_button_pressed[_column_num]){
    select_debounce_timer[_column_num] = millis();     //Start the debounce timer
    last_button_pressed[_column_num] = button_pressed[_column_num];   //Reset the last button pressed variable
  }

  //If the current button is a valid button and the debounce timer has run out
  if(button_pressed[_column_num] <= SELECT_BUTTONS_COUNT && (millis() - select_debounce_timer[_column_num]) >= BUTTON_PRESS_DEBOUNCE_TIME && column_btn_state[_column_num] == COLUMN_IDLE){

    //Update the variables that detects if a new button is pressed
    last_button_pressed_2[_column_num] = button_pressed[_column_num];
    column_btn_state[_column_num] = COLUMN_PRESSED;

    #ifdef DEBUG_BUTTON_PRESS_RELEASE
      Debug.print("Col");
      Debug.print(_column_num);
      Debug.print(": Button ");
      Debug.print(button_pressed[_column_num]);
      Debug.println(" Pressed");
    #endif

    button_press_callback(button_pressed[_column_num], _column_num, BUTTON_PRESSED);

  }


  //If the last button was no button and the debounce timer has run out
  if(last_button_pressed[_column_num] > SELECT_BUTTONS_COUNT && (millis() - select_debounce_timer[_column_num]) >= BUTTON_RELEASE_DEBOUNCE_TIME && column_btn_state[_column_num] == COLUMN_PRESSED){

    column_btn_state[_column_num] = COLUMN_IDLE;    //Update the button state

    #ifdef DEBUG_BUTTON_PRESS_RELEASE
      Debug.print("Col");
      Debug.print(_column_num);
      Debug.print(": Button ");
      Debug.print(last_button_pressed_2[_column_num]);
      Debug.println(" Released");
    #endif

    button_press_callback(button_pressed[_column_num], _column_num, BUTTON_RELEASED); //Log the button release

  }

}





void mc_button::read_menu_buttons(uint16_t analog_value){


  menu_button_pressed = get_menu_button_pressed(analog_value);

  #ifdef DEBUG_CURRENT_MENU_BUTTON
    if(menu_button_pressed == MENU_UP_BTN)Debug.print("UP");
    if(menu_button_pressed == MENU_DOWN_BTN)Debug.print("DOWN");
    if(menu_button_pressed == MENU_LEFT_BTN)Debug.print("LEFT");
    if(menu_button_pressed == MENU_RIGHT_BTN)Debug.print("RIGHT");
    if(menu_button_pressed == MENU_ENTER_BTN)Debug.print("ENTER");
    if(menu_button_pressed >= MENU_BUTTONS_COUNT)Debug.print("NO");
    Debug.println(" Menu Buttons Pressed");

  #endif

  
  //if the button changes
  if(menu_button_pressed != last_menu_button_pressed){
    menu_debounce_timer = millis();     //Start the debounce timer
    last_menu_button_pressed = menu_button_pressed;   //Reset the last button pressed variable
  }

  //If the last button was a valid button and the debounce timer has run out
  if(menu_button_pressed <= MENU_BUTTONS_COUNT && (millis() - menu_debounce_timer) >= BUTTON_PRESS_DEBOUNCE_TIME && menu_button_state == COLUMN_IDLE){

    //Update the variables that detects if a new button is pressed
    last_menu_button_pressed_2 = menu_button_pressed;
    menu_button_state = COLUMN_PRESSED;

    if(menu_button_pressed == MENU_UP_BTN)commands.run_command(commands.MENU_UP_COMMAND);
    if(menu_button_pressed == MENU_DOWN_BTN)commands.run_command(commands.MENU_DOWN_COMMAND);
    if(menu_button_pressed == MENU_LEFT_BTN)commands.run_command(commands.MENU_LEFT_COMMAND);
    if(menu_button_pressed == MENU_RIGHT_BTN)commands.run_command(commands.MENU_RIGHT_COMMAND);
    if(menu_button_pressed == MENU_ENTER_BTN)commands.run_command(commands.MENU_ENTER_COMMAND);

    #ifdef DEBUG_MENU_BUTTON_PRESS_RELEASE
      if(menu_button_pressed == MENU_UP_BTN)Debug.print("UP");
      if(menu_button_pressed == MENU_DOWN_BTN)Debug.print("DOWN");
      if(menu_button_pressed == MENU_LEFT_BTN)Debug.print("LEFT");
      if(menu_button_pressed == MENU_RIGHT_BTN)Debug.print("RIGHT");
      if(menu_button_pressed == MENU_ENTER_BTN)Debug.print("ENTER");
      Debug.println(" Menu Button Pressed");
    #endif

  }

  //If the last button was no button and the debounce timer has run out
  if(last_menu_button_pressed > MENU_BUTTONS_COUNT && (millis() - menu_debounce_timer) >= BUTTON_RELEASE_DEBOUNCE_TIME && menu_button_state == COLUMN_PRESSED){

    menu_button_state = COLUMN_IDLE;      //Update the button state

    #ifdef DEBUG_MENU_BUTTON_PRESS_RELEASE
      if(last_menu_button_pressed_2 == MENU_UP_BTN)Debug.print("UP");
      if(last_menu_button_pressed_2 == MENU_DOWN_BTN)Debug.print("DOWN");
      if(last_menu_button_pressed_2 == MENU_LEFT_BTN)Debug.print("LEFT");
      if(last_menu_button_pressed_2 == MENU_RIGHT_BTN)Debug.print("RIGHT");
      if(last_menu_button_pressed_2 == MENU_ENTER_BTN)Debug.print("ENTER");
      Debug.println(" Menu Button Released");
    #endif
    
    //Button release
  }

}






//Poll all the columns at a certain inteval
void mc_button::read_all_buttons(uint32_t _poll_rate){

  //Check if it is time to read the buttons again
  if(millis() - button_poll_timer > _poll_rate)
  {
    //Read the adc channels and store the data in the ADC buffer
    adc.read_adc_pins();

    //Read the main buttons
    read_button_column(COL1_BTN, adc.adc_avg[adc.COL1_ADC_BUFFER]);
    read_button_column(COL2_BTN, adc.adc_avg[adc.COL2_ADC_BUFFER]);
    read_button_column(COL3_BTN, adc.adc_avg[adc.COL3_ADC_BUFFER]);

    //Read the menu buttons
    read_menu_buttons(adc.adc_avg[adc.MENU_BTN_ADC_BUFFER]);

    //Reset the timer
    button_poll_timer = millis();

  }
}


void mc_button::button_press_callback(uint8_t _row, uint8_t _column, uint8_t _button_state){
  items.log_item(_row, _column, _button_state);
}
