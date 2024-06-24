//Platform includes
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//Local includes
#include "TASKS/include/mc_display_task.h"
#include "types.h"

#include "HAL/include/mc_display.h"


//External variables
extern uint8_t system_state;

//Local variables
uint8_t display_local_state = -1;

mc_display  display;




//Init function, only runs once
void display_task_init(){

    display.init();

}


//Periodic execute function, runs continuously
void display_task_periodic_execute(){

    switch(system_state){

        case STATE_INIT:

            //run this piece of code only once when entering this state
            if(display_local_state != system_state){
                
                display_local_state = system_state;
            }



        break;


        case STATE_WAITING_FOR_NETWORK:

            //run this piece of code only once when entering this state
            if(display_local_state != system_state){
                
                display_local_state = system_state;
            }




        break;


        case STATE_IDLE:

            //run this piece of code only once when entering this state
            if(display_local_state != system_state){
                
                display_local_state = system_state;
            }




        break;


        case STATE_SURGERY_BUSY:


            //run this piece of code only once when entering this state
            if(display_local_state != system_state){
                
                display_local_state = system_state;
            }






        break;

    }



    vTaskDelay(20/portTICK_PERIOD_MS);

}