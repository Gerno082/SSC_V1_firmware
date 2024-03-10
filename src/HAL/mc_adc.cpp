//local includes
#include "HAL/include/mc_adc.h"


#include "main.h"


mc_adc::mc_adc(){

}


mc_adc::~mc_adc(){

}


void mc_adc::init(){

  //Setup ADC pins
  adcAttachPin(COL1_BUTTON_PIN);
  adcAttachPin(COL2_BUTTON_PIN);
  adcAttachPin(COL3_BUTTON_PIN);
  adcAttachPin(MENU_BUTTON_PIN);
  analogSetPinAttenuation(COL1_BUTTON_PIN, ADC_11db);
  analogSetPinAttenuation(COL2_BUTTON_PIN, ADC_11db);
  analogSetPinAttenuation(COL3_BUTTON_PIN, ADC_11db);
  analogSetPinAttenuation(MENU_BUTTON_PIN, ADC_11db);
  
  //Wait some time for the changes to apply
  delay(100);

  //Fill the adc buffer by reading a bunch of adc values with a 1ms delay
  for(int i = 0; i < ADC_ROLLING_AVG_BUFFSIZE; i++){
    read_adc_pins();
    delay(1);
  }

}



//Poll the ADC pins and store the values in a buffer
void mc_adc::read_adc_pins(){



  //Read all the columns
  for(int i = 0; i < ADC_CHANNELS; i++){

    //subtract the oldest value
    adc_buf_sum[i] -= adc_buf[i][adc_buf_pos];

    //Put the newest value in the buffer
    adc_buf[i][adc_buf_pos] = analogRead(adc_pins[i]);

    //Add the newest value to the sum
    adc_buf_sum[i] += adc_buf[i][adc_buf_pos];

    //Calculate the new average
    adc_avg[i] = adc_buf_sum[i]/ADC_ROLLING_AVG_BUFFSIZE;

    #ifdef DEBUG_ADC
      Serial.print("  Col");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(adc_avg[i]);
      if(i == 3)Serial.println();
    #endif

  }

  //Increment the buffer position
  adc_buf_pos++;
  if(adc_buf_pos >= ADC_ROLLING_AVG_BUFFSIZE)adc_buf_pos = 0;

  //Restart the poll timer
  adc_poll_timer = millis();


}



