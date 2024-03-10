//Platform includes
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//Local includes
#include "TASKS/include/mc_control_task.h"
#include "HAL/include/mc_button.h"
#include "types.h"


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
                
                control_local_state = system_state;
            }



        break;


        case STATE_WAITING_FOR_WIFI:

            //run this piece of code only once when entering this state
            if(control_local_state != system_state){
                
                control_local_state = system_state;
            }




        break;


        case STATE_IDLE:

            //run this piece of code only once when entering this state
            if(control_local_state != system_state){
                
                control_local_state = system_state;
            }




        break;


        case STATE_SURGERY_BUSY:


            //run this piece of code only once when entering this state
            if(control_local_state != system_state){
                
                control_local_state = system_state;
            }






        break;

    }


    vTaskDelay(1/portTICK_PERIOD_MS);

}