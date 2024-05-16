//Platform includes

//Local includes
#include "mc_freertos.h"
#include "TASKS/include/mc_control_task.h"
#include "TASKS/include/mc_display_task.h"
#include "TASKS/include/mc_event_logger_task.h"
#include "TASKS/include/mc_i2c_task.h"
#include "TASKS/include/mc_wifi_task.h"


//External variables


//local variables


//freertos constructor
mc_freertos::mc_freertos(){

}


//freertos destructor
mc_freertos::~mc_freertos(){

}



//Start the freertos tasks
void mc_freertos::init(){

    //Create the tasks
    xTaskCreatePinnedToCore(control_task,       "control_task",         15000/*stack depth*/, NULL/*parameters*/, 5/*priority*/, &control_task_handle,      0/*Core ID*/);
    xTaskCreatePinnedToCore(display_task,       "display_task",         15000/*stack depth*/, NULL/*parameters*/, 3/*priority*/, &display_task_handle,      0/*Core ID*/);
    xTaskCreatePinnedToCore(event_logger_task,  "event_logger_task",    15000/*stack depth*/, NULL/*parameters*/, 2/*priority*/, &event_logger_task_handle, 0/*Core ID*/);
    xTaskCreatePinnedToCore(i2c_task,           "i2c_task",             15000/*stack depth*/, NULL/*parameters*/, 4/*priority*/, &i2c_task_handle,          1/*Core ID*/);
    xTaskCreatePinnedToCore(wifi_task,          "wifi_task",            15000/*stack depth*/, NULL/*parameters*/, 4/*priority*/, &wifi_task_handle,         1/*Core ID*/);

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
void mc_freertos::display_task(void * parameter){
    
    //task init
    display_task_init();

    //task periodic execute
    while(1){

        display_task_periodic_execute();

    }
}


/////////////////////////////////////////////////
// --------------- Serial Task --------------- //
/////////////////////////////////////////////////
void mc_freertos::event_logger_task(void * parameter){

    //task init
    event_logger_task_init();

    //task periodic execute
    while(1){

        event_logger_task_periodic_execute();

    }
}



/////////////////////////////////////////////////
// ---------------- WiFi Task ---------------- //
/////////////////////////////////////////////////
void mc_freertos::i2c_task(void * parameter){

    //task init
    i2c_task_init();

    //task periodic execute
    while(1){

        i2c_task_periodic_execute();

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