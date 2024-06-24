//Platform includes
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//Local includes
#include "TASKS/include/mc_i2c_task.h"
#include "HAL/include/mc_button.h"
#include "types.h"
#include "main.h"







//Define I2C port

#define SDA_pin 16
#define SCL_pin 17






mc_button button = mc_button(SDA_pin, SCL_pin);





bool menu_btn_ready = false;
bool check_btn_ready = false;


void check_btn_irq(){
 check_btn_ready = true;
}


void menu_btn_irq(){
 menu_btn_ready = true;
}




//Init function, only runs once
void i2c_task_init(){

    pinMode(15, OUTPUT);

    Serial.begin(115200);




    button.init();

    //Menu int
    pinMode(34, INPUT);
    // attachInterrupt(34, menu_btn_irq, FALLING);  //  todo verify


    //check int
    pinMode(23, INPUT);
    // attachInterrupt(23, check_btn_irq, FALLING);  //  todo verify

}


//Periodic execute function, runs continuously
void i2c_task_periodic_execute(){


    button.get_button_pressed();



    // button.check_debounce();




    // // check_btn_ready = true;
    // if(check_btn_ready == true){

    //     Serial.print("col0 button pressed:");
    //     for (int pin = 0; pin < 16; pin++){
    //         // int val = BTN0_PEX_COL0.read1(pin);
    //         // Serial.print(val);
    //         Serial.print('\t');
    //     }
    //     Serial.println();

    //     Serial.print("col1 button pressed:");
    //     for (int pin = 0; pin < 16; pin++){
    //         // int val = BTN0_PEX_COL1.read1(pin);
    //         // Serial.print(val);
    //         Serial.print('\t');
    //     }
    //     Serial.println();

    //     check_btn_ready = false;

    // }

    // // menu_btn_ready = true;
    // if(menu_btn_ready == true){

    //     Serial.print("menu button pressed:");
    //     for (int pin = 0; pin < 16; pin++){
    //         // int val = BTN_PEX_MENU.read1(pin);
    //         // Serial.print(val);
    //         Serial.print('\t');
    //     }
    //     Serial.println();

    //     menu_btn_ready = false;
    // }

    vTaskDelay(100/portTICK_PERIOD_MS);

}