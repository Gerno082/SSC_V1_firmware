//Platform includes

//Local includes
#include "HAL/include/mc_database.h"


//External variables


//local variables


mc_database::mc_database(){

}


mc_database::~mc_database(){

}


void mc_database::send_db_command(String base_string, String info_string){



}




void mc_database::send_button_to_db(String button_name, String button_state){


    String Message = "BTN_EVENT:{BTN:"+button_name+",STATE:"+button_state+",TIME:xxxx}";

    db_buffer[db_buf_pos] = Message;

    db_buf_pos++;

    if(db_buf_pos >= 100)db_buf_pos = 0;

    Serial.println(db_buf_pos+" "+Message);



}
