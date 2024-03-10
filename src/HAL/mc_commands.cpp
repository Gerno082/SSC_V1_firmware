//Platform includes
#include <stdint.h>

//Local includes
#include "HAL/include/mc_commands.h"

//External variables


//local variables


mc_commands::mc_commands(){

}


mc_commands::~mc_commands(){

}


void mc_commands::run_command(uint8_t command){

    switch (command){

        case START_SURGERY_COMMAND:
        
        break;


        case STOP_SURGERY_COMMAND:
        
        break;


        case CLEAR_BOARD_COMMAND:
        
        break;


        case MENU_UP_COMMAND:
        
        break;


        case MENU_DOWN_COMMAND:
        
        break;


        case MENU_LEFT_COMMAND:
        
        break;


        case MENU_RIGHT_COMMAND:
        
        break;


        case MENU_ENTER_COMMAND:
        
        break;



        default:

        break;
    }



}