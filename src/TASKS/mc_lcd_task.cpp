//Platform includes
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//Local includes
#include "TASKS/include/mc_lcd_task.h"
#include "types.h"


//External variables
extern uint8_t system_state;

//Local variables
uint8_t lcd_local_state = -1;


//Init function, only runs once
void lcd_task_init(){

}


//Periodic execute function, runs continuously
void lcd_task_periodic_execute(){

    switch(system_state){

        case STATE_INIT:

            //run this piece of code only once when entering this state
            if(lcd_local_state != system_state){
                
                lcd_local_state = system_state;
            }



        break;


        case STATE_WAITING_FOR_WIFI:

            //run this piece of code only once when entering this state
            if(lcd_local_state != system_state){
                
                lcd_local_state = system_state;
            }




        break;


        case STATE_IDLE:

            //run this piece of code only once when entering this state
            if(lcd_local_state != system_state){
                
                lcd_local_state = system_state;
            }




        break;


        case STATE_SURGERY_BUSY:


            //run this piece of code only once when entering this state
            if(lcd_local_state != system_state){
                
                lcd_local_state = system_state;
            }






        break;

    }



    vTaskDelay(20/portTICK_PERIOD_MS);

}