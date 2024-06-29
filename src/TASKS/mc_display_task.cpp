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

SPIClass* display_spi_bus;



bool display_init_done = false;

extern bool sd_init_done;


//Init function, only runs once
void display_task_init(SPIClass* spi_bus){

    display_spi_bus = spi_bus;

}


//Periodic execute function, runs continuously
void display_task_periodic_execute(){

    switch(system_state){

        case STATE_INIT:

            //run this piece of code only once when entering this state
            if(display_local_state != system_state){

                display_local_state = system_state;

                Serial.println("Display Init State");
                
            }


            //if the display has not been initialized
            if(display_init_done == false && sd_init_done == true){
                

                display.init(display_spi_bus);
                display_init_done=true;
                
            }



        break;


        case STATE_WAITING_FOR_NETWORK:

            //run this piece of code only once when entering this state
            if(display_local_state != system_state){

                display_local_state = system_state;

                Serial.println("Display Connecting State");

                display.connecting_screen();
                
                
            }




        break;


        case STATE_IDLE:

            //run this piece of code only once when entering this state
            if(display_local_state != system_state){

                display_local_state = system_state;

                Serial.println("Display Idle State");

                display.idle_screen();
                
                

            }



        break;


        case STATE_SURGERY_BUSY:


            //run this piece of code only once when entering this state
            if(display_local_state != system_state){

                display_local_state = system_state;

                Serial.println("Display Busy State");

                display.surgery_screen();
                
                
            }


        break;


        case STATE_UPLOAD_DATA:

            //run this piece of code only once when entering this state
            if(display_local_state != system_state){

                display_local_state = system_state;

                Serial.println("Display Upload State");

                display.upload_screen();
                
                
            }


        break;

    }


    vTaskDelay(5/portTICK_PERIOD_MS);

}