//Platform includes
#include <stdint.h>

//Local includes
#include "HAL/include/mc_commands.h"
#include "Arduino.h"
#include "types.h"

//External variables


//local variables


mc_commands::mc_commands(){

}


mc_commands::~mc_commands(){

}


extern uint8_t system_state;

void mc_commands::run_command(uint8_t command){


    switch (command){

        case START_SURG_CMD:

            Serial.println("Start Surgery");

            if(system_state == STATE_IDLE){

                

                system_state = STATE_SURGERY_BUSY;

            }

            
        
        break;


        case STOP_SURG_CMD:

            Serial.println("Stop Surgery");

            
            if(system_state == STATE_SURGERY_BUSY){

                

                system_state = STATE_IDLE;

            }

        
        break;


        case CLEAR_BOARD_CMD:
        
        break;


        case MENU_UP_CMD:
        
        break;


        case MENU_DOWN_CMD:
        
        break;


        case MENU_LEFT_CMD:
        
        break;


        case MENU_RIGHT_CMD:
        
        break;


        case MENU_ENTER_CMD:
        
        break;



        default:

        break;
    }



}