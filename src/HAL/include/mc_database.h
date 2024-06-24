#ifndef __MC_DATABASE_H__
#define __MC_DATABASE_H__

#include <stdint.h>

#include <Arduino.h>

class mc_database{

  public:

    mc_database();

    ~mc_database();

    void send_db_command(String, String);

    void send_button_to_db(String, String);


    String db_buffer[100];

    uint16_t db_buf_pos = 0;


    private:





};


#endif