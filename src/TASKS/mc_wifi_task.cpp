//Platform includes
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//Local includes
#include "TASKS/include/mc_wifi_task.h"
#include "types.h"


//External variables
extern uint8_t system_state;

//Local variables
uint8_t wifi_local_state = -1;


//Init function, only runs once
void wifi_task_init(){


}


//Periodic execute function, runs continuously
void wifi_task_periodic_execute(){

    
    switch(system_state){

        case STATE_INIT:

            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){
                
                wifi_local_state = system_state;
            }


        break;


        case STATE_WAITING_FOR_WIFI:

            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){
                
                wifi_local_state = system_state;
            }


        break;


        case STATE_IDLE:

            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){
                
                wifi_local_state = system_state;
            }


        break;


        case STATE_SURGERY_BUSY:


            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){
                
                wifi_local_state = system_state;
            }


        break;

    }

    vTaskDelay(20/portTICK_PERIOD_MS);

}