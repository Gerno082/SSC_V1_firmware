//Platform includes
#include <stdint.h>

//Local includes
#include "HAL/include/mc_commands.h"
#include "Arduino.h"
#include "types.h"

#include "HAL/include/mc_led.h"

//External variables

extern mc_led      led;


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



                Serial.print("State: ");
                Serial.println(system_state);

            }

            
        
        break;


        case STOP_SURG_CMD:

            Serial.println("Stop Surgery");

            
            if(system_state == STATE_SURGERY_BUSY){

                

                system_state = STATE_UPLOAD_DATA;

                led.update_all_leds(255, 0, 0);

                
                Serial.print("State: ");
                Serial.println(system_state);

            }

        
        break;


        case CLEAR_BOARD_CMD:

            led.update_all_leds(255, 0, 0);
        
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