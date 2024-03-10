//platform includes
#include <Arduino.h>

//local includes
#include "HAL/include/mc_log_events.h"
#include "HAL/include/mc_led.h"
#include "main.h"


extern mc_led led;


mc_items::mc_items(){

}


mc_items::~mc_items(){

}


void mc_items::init(){

}




void mc_items::log_item(uint8_t _row, uint8_t _column, uint8_t _button_state){

    // check if buttons is enabled   
    //Only enter if the button is being pressed (not released)
    if(_button_state == BUTTON_PRESSED && (millis() - button_block_timer >= BUTTON_BLOCK_TIME) && logging_enabled == true){

        button_block_timer = millis();

        //iterate through all the items in the struct
        for(int item_num = 0; item_num < 24; item_num++){



            //if the current button column is defined in the current item
            if(ITEMS[item_num].column == _column){


                //if this is a dual state button and the button was pressed
                if(ITEMS[item_num].btn[0] == _row && ITEMS[item_num].type == ITEM_TYPE_DUAL_STATE){

                    if(ITEMS[item_num].state == UNCHECKED){

                        //change state
                        ITEMS[item_num].state = CHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" checked");
                        #endif

                        //Update LED
                        led.set_LED_colour(ITEMS[item_num].btn[0]-1, _column, 0, LED_BRIGHTNESS, 0);

                        //execute command
                        commands.run_command(ITEMS[item_num].command[0]);

                        //send to database
                        database.send_db_command(item_strings[item_num], CHECKED_STRING);

                        //break from for loop
                        item_num = 24;
                        break;
                    }//ITEM == UNCHECKED

                    //if it is a Dual state item and if the state is not checked, and the checked button was pressed, go to checked
                    if(ITEMS[item_num].state == CHECKED){

                        //change state
                        ITEMS[item_num].state = UNCHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" unchecked");
                        #endif

                        //Update LED
                        led.set_LED_colour(ITEMS[item_num].btn[0]-1, _column, LED_BRIGHTNESS, 0, 0);

                        //execute command
                        commands.run_command(ITEMS[item_num].command[0]);

                        //send to database
                        database.send_db_command(item_strings[item_num], UNCHECKED_STRING);

                        //break from for loop
                        item_num = 24;
                        break;
                    }//ITEM == CHECKED

                }




                //if this is a tri state item and the first button was pressed
                if(ITEMS[item_num].btn[0] == _row && ITEMS[item_num].type == ITEM_TYPE_TRI_STATE){

                    //if it is a Tri state item and if the state is YES, and the YES button was pressed, uncheck the item
                    if(ITEMS[item_num].state == CHECKED_YES){

                        //change state
                        ITEMS[item_num].state = UNCHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" unchecked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0]-1, _column, LED_BRIGHTNESS, 0, 0);    //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1]-1, _column, LED_BRIGHTNESS, 0, 0);    //NA LED
                                                
                        //execute command
                        commands.run_command(ITEMS[item_num].command[0]);

                        //send to database
                        database.send_db_command(item_strings[item_num], UNCHECKED_STRING);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM == CHECKED_YES

                    //if it is a Tri state item and if the state is not YES, and the YES button was pressed, go to YES
                    if(ITEMS[item_num].state != CHECKED_YES){

                        //change state
                        ITEMS[item_num].state = CHECKED_YES;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" YES checked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0]-1, _column, 0, LED_BRIGHTNESS, 0);    //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1]-1, _column, 0, 0, 0);                 //NA LED
                        
                        //execute command
                        commands.run_command(ITEMS[item_num].command[0]);

                        //send to database
                        database.send_db_command(item_strings[item_num], CHECKED_YES_STRING);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM != CHECKED_YES
                
                }


                //if this is a tri state item and the second button was pressed
                if(ITEMS[item_num].btn[1] == _row && ITEMS[item_num].type == ITEM_TYPE_TRI_STATE){


                    //if it is a Tri state item and if the state is not N/A, and the N/A button was pressed, go to N/A
                    if(ITEMS[item_num].state == CHECKED_NA){

                        //change state
                        ITEMS[item_num].state = UNCHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" unchecked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0]-1, _column, LED_BRIGHTNESS, 0, 0);    //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1]-1, _column, LED_BRIGHTNESS, 0, 0);    //NA LED

                        //execute command
                        commands.run_command(ITEMS[item_num].command[1]);

                        //send to database
                        database.send_db_command(item_strings[item_num], UNCHECKED_STRING);
                        
                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM == CHECKED_NA


                    //if it is a Tri state item and if the state is not N/A, and the N/A button was pressed, go to N/A
                    if(ITEMS[item_num].state != CHECKED_NA){

                        //change state
                        ITEMS[item_num].state = CHECKED_NA;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" N/A checked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0]-1, _column, 0, 0, 0);                 //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1]-1, _column, 0, LED_BRIGHTNESS, 0);    //NA LED

                        //execute command
                        commands.run_command(ITEMS[item_num].command[1]);

                        //send to database
                        database.send_db_command(item_strings[item_num], CHECKED_NA_STRING);
                        
                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM != CHECKED_NA

                }


            }//ITEM_row == _row && ITEM_column == _column



            //if we come across an item that is unchecked, do not look further and break from the loop
            if(ITEMS[item_num].state == UNCHECKED){
                item_num = 24;
                return;
            }

        
        
        }   //items for loop

    
    }//if block time has runout && logging enabled

}//void log_item
