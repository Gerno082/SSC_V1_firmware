//Platform includes
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//Local includes
#include "TASKS/include/mc_i2c_task.h"
#include "types.h"
#include "main.h"




//Init function, only runs once
void i2c_task_init(){


}


//Periodic execute function, runs continuously
void i2c_task_periodic_execute(){



    vTaskDelay(1/portTICK_PERIOD_MS);

}