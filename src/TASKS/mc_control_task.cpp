//Platform includes
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//Local includes
#include "TASKS/include/mc_control_task.h"
#include "HAL/include/mc_button.h"
#include "types.h"
#include "main.h"


//External variables
extern mc_button button;
extern uint8_t system_state;

//local variables
uint8_t control_local_state = -1;


//Init function, only runs once
void control_task_init(){


}


//Periodic execute function, runs continuously
void control_task_periodic_execute(){

    button.read_all_buttons(1);


    switch(system_state){


        case STATE_INIT:

            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering init state");
                #endif
                
                control_local_state = system_state;
            }



        break;


        case STATE_WAITING_FOR_NETWORK:

            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering waiting for Network state");
                #endif
                
                control_local_state = system_state;
            }




        break;


        case STATE_NETWORK_CONNECTING:

            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering Network connecting state");
                #endif
                
                control_local_state = system_state;
            }


        break;


        case STATE_IDLE:


            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering Idle state");
                #endif
                
                control_local_state = system_state;
            }

        break;


        case STATE_UPLOAD_DATA:


            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering Data Upload state");
                #endif
                
                control_local_state = system_state;
            }

        break;


        case STATE_POWER_DOWN:


            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering Power Down state");
                #endif
                
                control_local_state = system_state;
            }

        break;









    }


    vTaskDelay(1/portTICK_PERIOD_MS);

}