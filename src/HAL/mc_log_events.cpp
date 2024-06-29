//platform includes
#include <Arduino.h>

//local includes
#include "HAL/include/mc_log_events.h"
#include "HAL/include/mc_led.h"
#include "main.h"

//External variables
extern mc_led led;
extern mc_database database;

//local variables


mc_items::mc_items(){

}


mc_items::~mc_items(){

}


void mc_items::init(){

}




void mc_items::log_item(uint8_t button, uint8_t _column, uint8_t _button_state){



    // Serial.print(" Col:");
    // Serial.print(_column);
    // Serial.print(" BTN:");
    // Serial.print(button);
    // Serial.print(" STATE:");
    // Serial.println(_button_state);


    // check if buttons is enabled   
    //Only enter if the button is being pressed (not released)
    if(_button_state == BUTTON_PRESSED && (millis() - button_block_timer >= BUTTON_BLOCK_TIME) && logging_enabled == true){

        button_block_timer = millis();




        //iterate through all the items in the struct
        for(int item_num = 0; item_num < 23; item_num++){



            //if the current button column is defined in the current item
            if(ITEMS[item_num].column == _column){


                


                //if this is a dual state button and the button was pressed
                if(ITEMS[item_num].btn[0] == button && ITEMS[item_num].type == ITEM_TYPE_DUAL_STATE){

                    if(ITEMS[item_num].state == UNCHECKED){

                        //change state
                        ITEMS[item_num].state = CHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" checked");
                        #endif

                        //Update LED
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, 0, LED_BRIGHTNESS, 0);

                        //send to database
                        database.send_button_to_db(button_names[item_num], CHECKED_STRING);

                        //execute command
                        cmd.run_command(ITEMS[item_num].command[CHECKED_COMMAND]);
   
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
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, LED_BRIGHTNESS, 0, 0);

                        //send to database
                        database.send_button_to_db(button_names[item_num], UNCHECKED_STRING);

                        //execute command
                        cmd.run_command(ITEMS[item_num].command[UNCHECKED_COMMAND]);

                        //break from for loop
                        item_num = 24;
                        break;
                    }//ITEM == CHECKED

                }




                //if this is a tri state item and the first button was pressed
                if(ITEMS[item_num].btn[0] == button && ITEMS[item_num].type == ITEM_TYPE_TRI_STATE){

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
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, LED_BRIGHTNESS, 0, 0);    //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, LED_BRIGHTNESS, 0, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], UNCHECKED_STRING);
                                                
                        //execute command
                        cmd.run_command(ITEMS[item_num].command[UNCHECKED_COMMAND]);

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
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, 0, LED_BRIGHTNESS, 0);    //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, 0, 0, 0);                 //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], CHECKED_YES_STRING);
                        
                        //execute command
                        cmd.run_command(ITEMS[item_num].command[YES_CHECKED_COMMAND]);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM != CHECKED_YES
                
                }


                //if this is a tri state item and the second button was pressed
                if(ITEMS[item_num].btn[1] == button && ITEMS[item_num].type == ITEM_TYPE_TRI_STATE){


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
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, LED_BRIGHTNESS, 0, 0);    //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, LED_BRIGHTNESS, 0, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], UNCHECKED_STRING);

                        //execute command
                        cmd.run_command(ITEMS[item_num].command[UNCHECKED_COMMAND]);
                        
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
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, 0, 0, 0);                 //YES LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, 0, LED_BRIGHTNESS, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], CHECKED_NA_STRING);

                        //execute command
                        cmd.run_command(ITEMS[item_num].command[NA_CHECKED_COMMAND]);
                        
                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM != CHECKED_NA

                }








                //if this is a quad state item and the first button was pressed
                if(ITEMS[item_num].btn[0] == button && ITEMS[item_num].type == ITEM_TYPE_QUAD_STATE){

                    //if it is a Tri state item and if the state is L, and the L button was pressed, uncheck the item
                    if(ITEMS[item_num].state == CHECKED_L){

                        //change state
                        ITEMS[item_num].state = UNCHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" unchecked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, LED_BRIGHTNESS, 0, 0);    //L LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, LED_BRIGHTNESS, 0, 0);    //R LED
                        led.set_LED_colour(ITEMS[item_num].btn[2], _column, LED_BRIGHTNESS, 0, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], UNCHECKED_STRING);
                                                
                        //execute command
                        cmd.run_command(ITEMS[item_num].command[UNCHECKED_COMMAND]);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM == CHECKED_L

                    //if it is a Quad state item and if the state is not L, and the L button was pressed, go to L
                    if(ITEMS[item_num].state != CHECKED_L){

                        //change state
                        ITEMS[item_num].state = CHECKED_L;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" L checked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, 0, LED_BRIGHTNESS, 0);    //L LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, 0, 0, 0);    //R LED
                        led.set_LED_colour(ITEMS[item_num].btn[2], _column, 0, 0, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], CHECKED_L_STRING);
                        
                        //execute command
                        cmd.run_command(ITEMS[item_num].command[L_CHECKED_COMMAND]);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM != CHECKED_L
                
                }





                //if this is a quad state item and the second button was pressed
                if(ITEMS[item_num].btn[1] == button && ITEMS[item_num].type == ITEM_TYPE_QUAD_STATE){

                    //if it is a Tri state item and if the state is R, and the R button was pressed, uncheck the item
                    if(ITEMS[item_num].state == CHECKED_R){

                        //change state
                        ITEMS[item_num].state = UNCHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" unchecked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, LED_BRIGHTNESS, 0, 0);    //L LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, LED_BRIGHTNESS, 0, 0);    //R LED
                        led.set_LED_colour(ITEMS[item_num].btn[2], _column, LED_BRIGHTNESS, 0, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], UNCHECKED_STRING);
                                                
                        //execute command
                        cmd.run_command(ITEMS[item_num].command[UNCHECKED_COMMAND]);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM == CHECKED_R

                    //if it is a Quad state item and if the state is not R, and the R button was pressed, go to R
                    if(ITEMS[item_num].state != CHECKED_R){

                        //change state
                        ITEMS[item_num].state = CHECKED_R;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" R checked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, 0, 0, 0);    //L LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, 0, LED_BRIGHTNESS, 0);    //R LED
                        led.set_LED_colour(ITEMS[item_num].btn[2], _column, 0, 0, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], CHECKED_R_STRING);
                        
                        //execute command
                        cmd.run_command(ITEMS[item_num].command[R_CHECKED_COMMAND]);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM != CHECKED_L
                
                }




                
                //if this is a quad state item and the third button was pressed
                if(ITEMS[item_num].btn[2] == button && ITEMS[item_num].type == ITEM_TYPE_QUAD_STATE){


                    //if it is a Quad state item and if the state is not N/A, and the N/A button was pressed, go to N/A
                    if(ITEMS[item_num].state == CHECKED_NA){

                        //change state
                        ITEMS[item_num].state = UNCHECKED;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" unchecked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, LED_BRIGHTNESS, 0, 0);    //L LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, LED_BRIGHTNESS, 0, 0);    //R LED
                        led.set_LED_colour(ITEMS[item_num].btn[2], _column, LED_BRIGHTNESS, 0, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], UNCHECKED_STRING);
                        
                        //execute command
                        cmd.run_command(ITEMS[item_num].command[UNCHECKED_COMMAND]);

                        //break from for loop
                        item_num = 24;
                        break;

                    }//ITEM == CHECKED_NA


                    //if it is a Quad state item and if the state is not N/A, and the N/A button was pressed, go to N/A
                    if(ITEMS[item_num].state != CHECKED_NA){

                        //change state
                        ITEMS[item_num].state = CHECKED_NA;

                        #ifdef DEBUG_ITEMS
                            Debug.print("Item ");
                            Debug.print(item_num);
                            Debug.println(" N/A checked");
                        #endif

                        //Update LEDs
                        led.set_LED_colour(ITEMS[item_num].btn[0], _column, 0, 0, 0);    //L LED
                        led.set_LED_colour(ITEMS[item_num].btn[1], _column, 0, 0, 0);    //R LED
                        led.set_LED_colour(ITEMS[item_num].btn[2], _column, 0, LED_BRIGHTNESS, 0);    //NA LED

                        //send to database
                        database.send_button_to_db(button_names[item_num], CHECKED_NA_STRING);

                        //execute command
                        cmd.run_command(ITEMS[item_num].command[NA_CHECKED_COMMAND]);

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
