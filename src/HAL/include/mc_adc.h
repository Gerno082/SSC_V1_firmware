#ifndef __MC_ADC_H__
#define __MC_ADC_H__

//Platform includes
#include <Arduino.h>


//ADC buffer size
#define ADC_ROLLING_AVG_BUFFSIZE    20

//ADC poll rate in milliseconds
#define ADC_POLL_RATE  1


//Pins definition
#define COL1_BUTTON_PIN     32
#define COL2_BUTTON_PIN     35
#define COL3_BUTTON_PIN     34
#define MENU_BUTTON_PIN     33 

//Define how many adc channels we are going to use, to define the buffer sizes
#define ADC_CHANNELS        4


class mc_adc{

  public:
    mc_adc();

    ~mc_adc();

    void init();

    void read_adc_pins();


    //Put all the ADC pins in an array
    uint8_t adc_pins[ADC_CHANNELS] = {COL1_BUTTON_PIN, COL2_BUTTON_PIN, COL3_BUTTON_PIN, MENU_BUTTON_PIN};

    //The order of the button pins in the ADC buffer
    enum adc_buffer_items{
      COL1_ADC_BUFFER = 0,
      COL2_ADC_BUFFER = 1,
      COL3_ADC_BUFFER = 2,
      MENU_BTN_ADC_BUFFER = 3
    };


    // CheckList Button Variables
    uint16_t adc_buf[ADC_CHANNELS][ADC_ROLLING_AVG_BUFFSIZE] = {0};        //Buffer to store the ADC values of each column
    uint16_t adc_avg[ADC_CHANNELS] = {0};                                  //Buffer to store the avg of each column
    uint32_t adc_buf_sum[ADC_CHANNELS] = {0};                              //buffer to store the sum of each column
    uint32_t adc_buf_pos = 0;                                   //Current position in the buffer
    unsigned long adc_poll_timer = 0;                           //Timekeeping variable used to poll the adc



  private:



};






#endif  //__MC_ADC_H__