//Platform includes
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <SPI.h>

#include "SD.h"

//Local includes
#include "TASKS/include/mc_control_task.h"
#include "HAL/include/mc_sd.h"
#include "HAL/include/mc_database.h"
#include "types.h"
#include "main.h"


//External variables

extern uint8_t system_state;

//local variables
uint8_t control_local_state = -1;

mc_sd sd;


extern mc_database database;


SPIClass* sd_spi_bus;



//Init function, only runs once
void control_task_init(SPIClass* spi_bus){

    sd_spi_bus = spi_bus;

    Serial.println("0");

}

bool sd_init_done = false;

extern bool wifi_init_done;
extern bool i2c_init_done;
extern bool display_init_done;


extern QueueHandle_t QueueHandle;



//Periodic execute function, runs continuously
void control_task_periodic_execute(){

    // button.read_all_buttons(1);


    // Debug.println("Control run");


    switch(system_state){


        case STATE_INIT:

            //run this piece of code only once when entering this state
            if(control_local_state != system_state){

                #ifdef DEBUG_STATES
                    Debug.println("Entering init state");
                #endif

                sd.init(sd_spi_bus);

                sd_init_done = true;
                
                control_local_state = system_state;
            }

            // Serial.println("test1");

            //Wait for everything to init before going to the next state
            if(wifi_init_done==true && i2c_init_done==true && sd_init_done == true && display_init_done==true){
                system_state = STATE_WAITING_FOR_NETWORK;

                Serial.println("Waiting for network");
            }

            // Serial.println("test2");



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


                // for(int i = 0; i < database.db_buf_pos; i++){

                //     char tempArr[100] = {0};
                    
                //     database.db_buffer[i].toCharArray(tempArr, 100);

                //     sd.appendFile(SD, "/Test.txt", tempArr);
                // }


                sd.readfile(SD, "/Test.txt");


                vTaskDelay(20/portTICK_PERIOD_MS);


                system_state = STATE_IDLE;
                
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



    // Serial.println("test3");


    if(sd_init_done == true){

        message_t message;

        if (QueueHandle != NULL) {  // Sanity check just to make sure the queue actually exists


        if(uxQueueMessagesWaiting(QueueHandle) > 0){

            int ret = xQueueReceive(QueueHandle, &message, portMAX_DELAY);

            if (ret == pdPASS) {
                // The message was successfully received - send it back to Serial port and "Echo: "

                sd.appendFile(SD, "/Test.txt", message.string);


                // String button_message = String(message.string);

                // Serial.println(button_message);


            } else if (ret == pdFALSE) {
                Serial.println("The task was unable to receive data from the Queue");
            }


        }

        }  // Sanity check

    }


    // Serial.println("test4");


    vTaskDelay(5/portTICK_PERIOD_MS);

}