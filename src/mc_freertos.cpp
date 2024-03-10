#include "mc_freertos.h"

#include "TASKS/include/mc_control_task.h"
#include "TASKS/include/mc_lcd_task.h"
#include "TASKS/include/mc_serial_task.h"
#include "TASKS/include/mc_wifi_task.h"



//freertos constructor
mc_freertos::mc_freertos(){

}


//freertos destructor
mc_freertos::~mc_freertos(){

}



//Start the freertos tasks
void mc_freertos::init(){

    //Create the tasks
    xTaskCreatePinnedToCore(control_task,   "control_task",     15000/*stack depth*/, NULL/*parameters*/, 1/*priority*/, &control_task_handle,  0/*Core ID*/);
    xTaskCreatePinnedToCore(lcd_task,       "lcd_task",         15000/*stack depth*/, NULL/*parameters*/, 1/*priority*/, &lcd_task_handle,      0/*Core ID*/);
    xTaskCreatePinnedToCore(serial_task,    "serial_task",      15000/*stack depth*/, NULL/*parameters*/, 1/*priority*/, &serial_task_handle,   0/*Core ID*/);
    xTaskCreatePinnedToCore(wifi_task,      "wifi_task",        15000/*stack depth*/, NULL/*parameters*/, 1/*priority*/, &wifi_task_handle,     1/*Core ID*/);

}


/////////////////////////////////////////////////
// -------------- Hardware Task -------------- //
/////////////////////////////////////////////////
void mc_freertos::control_task(void * paramter){

    //task init
    control_task_init();

    //task periodic execute
    while(1){

        control_task_periodic_execute();

    }

}


////////////////////////////////////////////////
// ---------------- LCD Task ---------------- //
////////////////////////////////////////////////
void mc_freertos::lcd_task(void * parameter){
    
    //task init
    lcd_task_init();

    //task periodic execute
    while(1){

        lcd_task_periodic_execute();

    }
}


/////////////////////////////////////////////////
// --------------- Serial Task --------------- //
/////////////////////////////////////////////////
void mc_freertos::serial_task(void * parameter){

    //task init
    serial_task_init();

    //task periodic execute
    while(1){

        serial_task_periodic_execute();

    }
}


/////////////////////////////////////////////////
// ---------------- WiFi Task ---------------- //
/////////////////////////////////////////////////
void mc_freertos::wifi_task(void * parameter){

    //task init
    wifi_task_init();

    //task periodic execute
    while(1){

        wifi_task_periodic_execute();

    }
}