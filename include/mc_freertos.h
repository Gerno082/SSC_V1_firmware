#ifndef __MC_FREERTOS_H__
#define __MC_FREERTOS_H__

#include <Arduino.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>




class mc_freertos{

    public:
        mc_freertos();

        ~mc_freertos();

        void init();


        

        static void control_task(void * paramter);
        static void display_task(void * paramter);
        static void event_logger_task(void * paramter);
        static void i2c_task(void * paramter);
        static void wifi_task(void * paramter);





    private:

        TaskHandle_t control_task_handle = NULL;
        TaskHandle_t display_task_handle = NULL;
        TaskHandle_t event_logger_task_handle = NULL;
        TaskHandle_t i2c_task_handle = NULL;
        TaskHandle_t wifi_task_handle = NULL;
};


#endif  //__MC_FREERTOS_H__