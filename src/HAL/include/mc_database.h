#ifndef __MC_DATABASE_H__
#define __MC_DATABASE_H__

#include <stdint.h>

#include <Arduino.h>

class mc_database{

  public:

    mc_database();

    ~mc_database();

    void send_db_command(String, String);


    private:





};


#endif