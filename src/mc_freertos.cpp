//Platform includes
#include <SPI.h>

//Local includes
#include "mc_freertos.h"
#include "TASKS/include/mc_control_task.h"
#include "TASKS/include/mc_display_task.h"
#include "TASKS/include/mc_event_logger_task.h"
#include "TASKS/include/mc_i2c_task.h"
#include "TASKS/include/mc_wifi_task.h"


#include "types.h"


//External variables


//local variables




#define MAX_STRING_LENGTH   100


// Define Queue handle
QueueHandle_t QueueHandle;






SPIClass hspi(HSPI);


//freertos constructor
mc_freertos::mc_freertos(){

}


//freertos destructor
mc_freertos::~mc_freertos(){

}



//Start the freertos tasks
void mc_freertos::init(){

    hspi.begin(/*SCK*/14, /*MISO*/12, /*MOSI*/13, /*SS*/26);



    // Create the queue which will have <QueueElementSize> number of elements, each of size `message_t` and pass the address to <QueueHandle>.
    QueueHandle = xQueueCreate(QUEUE_ELEMENT_SIZE, sizeof(message_t));

    // Check if the queue was successfully created
    if (QueueHandle == NULL) {
        Serial.println("Queue could not be created. Halt.");
        while (1) {
            delay(1000);  // Halt at this point as is not possible to continue
        }
    }



    //Create the tasks

    

    xTaskCreatePinnedToCore(wifi_task,          "wifi_task",            10000/*stack depth*/, NULL/*parameters*/, 4/*priority*/, &wifi_task_handle,         1/*Core ID*/);
    xTaskCreatePinnedToCore(control_task,       "control_task",         10000/*stack depth*/, NULL/*parameters*/, 2/*priority*/, &control_task_handle,      0/*Core ID*/);
    xTaskCreatePinnedToCore(i2c_task,           "i2c_task",             10000/*stack depth*/, NULL/*parameters*/, 3/*priority*/, &i2c_task_handle,          1/*Core ID*/);
    xTaskCreatePinnedToCore(display_task,       "display_task",         10000/*stack depth*/, NULL/*parameters*/, 1/*priority*/, &display_task_handle,      0/*Core ID*/);
    

    
    // xTaskCreatePinnedToCore(event_logger_task,  "event_logger_task",    50000/*stack depth*/, NULL/*parameters*/, 2/*priority*/, &event_logger_task_handle, 1/*Core ID*/);

 

}


/////////////////////////////////////////////////
// -------------- Hardware Task -------------- //
/////////////////////////////////////////////////
void mc_freertos::control_task(void * paramter){

    vTaskDelay(20/portTICK_PERIOD_MS);

    //task init
    control_task_init(&hspi);

    //task periodic execute
    while(1){

        control_task_periodic_execute();


        
        // Serial.println("Control running");
        // vTaskDelay(10/portTICK_PERIOD_MS);
        
    }

}


////////////////////////////////////////////////
// ---------------- LCD Task ---------------- //
////////////////////////////////////////////////
void mc_freertos::display_task(void * parameter){

    vTaskDelay(20/portTICK_PERIOD_MS);

    //task init
    display_task_init(&hspi);

    //task periodic execute
    while(1){

        display_task_periodic_execute();

        
        // Serial.println("Display running");
        // vTaskDelay(10/portTICK_PERIOD_MS);

    }
}


/////////////////////////////////////////////////
// --------------- Serial Task --------------- //
/////////////////////////////////////////////////
void mc_freertos::event_logger_task(void * parameter){

    vTaskDelay(20/portTICK_PERIOD_MS);

    //task init
    event_logger_task_init();

    //task periodic execute
    while(1){

        event_logger_task_periodic_execute();

        
        // Serial.println("events running");
        // vTaskDelay(10/portTICK_PERIOD_MS);

    }
}



/////////////////////////////////////////////////
// ---------------- WiFi Task ---------------- //
/////////////////////////////////////////////////
void mc_freertos::i2c_task(void * parameter){

    vTaskDelay(20/portTICK_PERIOD_MS);

    // Serial.println("Testing123");

    //task init
    i2c_task_init();

    //task periodic execute
    while(1){

        i2c_task_periodic_execute();
        // Serial.println("i2c running");
        // vTaskDelay(10/portTICK_PERIOD_MS);
        

    }
}




/////////////////////////////////////////////////
// ---------------- WiFi Task ---------------- //
/////////////////////////////////////////////////
void mc_freertos::wifi_task(void * parameter){

    vTaskDelay(20/portTICK_PERIOD_MS);

    //task init
    wifi_task_init();

    Serial.println("Test1");

    //task periodic execute
    while(1){


        // Serial.println("Run");

        wifi_task_periodic_execute();

        // vTaskDelay(10/portTICK_PERIOD_MS);
        // Serial.println("wifi running");

    }
}