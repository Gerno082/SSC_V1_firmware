//Platform includes

//Local includes
#include "HAL/include/mc_database.h"

#include "types.h"


//External variables


//local variables


mc_database::mc_database(){

}


mc_database::~mc_database(){

}


void mc_database::send_db_command(){

    // for(int i = 0; i < db_buf_pos; i++){
    //     Serial.println(db_buf_pos+" "+db_buffer[i]);
    // }

}

extern QueueHandle_t QueueHandle;


void mc_database::send_button_to_db(String button_name, String button_state){





    String Message = "BTN_EVENT:{BTN:"+button_name+",STATE:"+button_state+",TIME:xxxx}\n";


    message_t message;

    Message.toCharArray(message.string, QUEUE_STRING_LENGTH);



    

    // Check if the queue exists AND if there is any free space in the queue
    if (QueueHandle != NULL && uxQueueSpacesAvailable(QueueHandle) > 0) {
        
        
        // The line needs to be passed as pointer to void.
        // The last parameter states how many milliseconds should wait (keep trying to send) if is not possible to send right away.
        // When the wait parameter is 0 it will not wait and if the send is not possible the function will return errQUEUE_FULL
        int ret = xQueueSend(QueueHandle, (void *)&message, 0);
        if (ret == pdTRUE) {
          // The message was successfully sent.
        } else if (ret == errQUEUE_FULL) {
          // Since we are checking uxQueueSpacesAvailable this should not occur, however if more than one task should
          //   write into the same queue it can fill-up between the test and actual send attempt
          Serial.println("The task was unable to send data into the Queue");
        }  // Queue send check
    }  // Queue sanity check


    for(int i = 0; i < 10; i++){

      vTaskDelay(1/portTICK_PERIOD_MS);

      if(uxQueueMessagesWaiting(QueueHandle) == 0)break;

    }

    // db_buffer[db_buf_pos] = Message;

    // db_buf_pos++;

    // if(db_buf_pos >= 100)db_buf_pos = 0;

    // Serial.println(db_buf_pos+" "+Message);



}
