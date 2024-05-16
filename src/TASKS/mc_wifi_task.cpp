//Platform includes
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <WiFi.h>

//Local includes
#include "TASKS/include/mc_wifi_task.h"
#include "types.h"
#include "main.h"


//External variables
extern uint8_t system_state;

//Local variables
uint8_t wifi_local_state = -1;


//Init function, only runs once
void wifi_task_init(){


}


//Periodic execute function, runs continuously
void wifi_task_periodic_execute(){

    unsigned long wifi_start_time;

    
    switch(system_state){

        case STATE_INIT:


            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){

                #ifdef DEBUG_WIFI
                    Debug.println("WIFI Init");
                #endif

                restart_wifi();



                
                wifi_local_state = system_state;
            }


        break;


        case STATE_WAITING_FOR_NETWORK:

            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){

                //save the start time of the wifi connection
                wifi_start_time = millis();
                
                wifi_local_state = system_state;
            }


            if(WiFi.status() == WL_CONNECTED){

                #ifdef DEBUG_WIFI
                    Debug.println("WIFI connected");
                #endif

                system_state = STATE_IDLE;

                break;
            }


            if(millis() - wifi_start_time > WIFI_START_CONNECTION_TIMEOUT){

                #ifdef DEBUG_WIFI
                    Debug.println("WiFi connect timeout");
                #endif

                restart_wifi();

                //save the start time of the wifi connection
                wifi_start_time = millis();

            }

        


        break;


        case STATE_IDLE:

            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){
                
                wifi_local_state = system_state;
            }

            check_wifi_connection(WIFI_CONNECTION_CHECK_RATE);


        break;


        case STATE_SURGERY_BUSY:


            //run this piece of code only once when entering this state
            if(wifi_local_state != system_state){
                
                wifi_local_state = system_state;
            }

            check_wifi_connection(WIFI_CONNECTION_CHECK_RATE);


        break;

    }

    vTaskDelay(20/portTICK_PERIOD_MS);

}


void restart_wifi(){

    #ifdef DEBUG_WIFI
        Debug.println("Disconnection from WiFi");
    #endif

    // disconnect WiFi
    WiFi.disconnect(true);

    // delay for 1 second
    delay(1000);

    #ifdef DEBUG_WIFI
        Debug.println("Setting WiFi to Station mode");
    #endif

    // set wifi to station mode
    WiFi.mode(WIFI_STA);

    #ifdef DEBUG_WIFI
        Debug.println("Setting WiFi hostname");
    #endif

    //Set the host name
    WiFi.setHostname("MCCL-DEV");

    #ifdef DEBUG_WIFI 
        Debug.println("Starting WiFi Connection");
    #endif

    //Start the WiFi connection with the default parameters
    WiFi.begin(DEFAULT_SSID, DEFAULT_PASSWORD);

}



//Function to check the WiFi connection at the check_time rate
void check_wifi_connection(unsigned long check_time){

    //not sure if this variable will work if define here
    unsigned long last_check_time;

    if(millis() - last_check_time > check_time){

        #ifdef DEBUG_WIFI 
            Debug.println("Checking WiFi connection");
        #endif


        last_check_time = millis();
    }

}