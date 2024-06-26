//Platform includes
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <SPI.h>

//Local includes
#include "TASKS/include/mc_control_task.h"
#include "HAL/include/mc_sd.h"
#include "types.h"
#include "main.h"


//External variables

extern uint8_t system_state;

//local variables
uint8_t control_local_state = -1;

mc_sd sd;


//Init function, only runs once
void control_task_init(SPIClass* spi_bus){

    sd.init(spi_bus);


}



extern bool wifi_init_done;
extern bool i2c_init_done;
extern bool display_init_done;


//Periodic execute function, runs continuously
void control_task_periodic_execute(){

    // button.read_all_buttons(1);


    switch(system_state){


        case STATE_INIT:

            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering init state");
                #endif
                
                control_local_state = system_state;
            }

            if(wifi_init_done==true && i2c_init_done==true && display_init_done==true){
                system_state = STATE_WAITING_FOR_NETWORK;
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