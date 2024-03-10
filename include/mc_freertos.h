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
        static void lcd_task(void * paramter);
        static void serial_task(void * paramter);
        static void wifi_task(void * paramter);





    private:

        TaskHandle_t control_task_handle = NULL;
        TaskHandle_t lcd_task_handle = NULL;
        TaskHandle_t serial_task_handle = NULL;
        TaskHandle_t wifi_task_handle = NULL;
};


#endif  //__MC_FREERTOS_H__