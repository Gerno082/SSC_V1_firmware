#ifndef __MC_COMMANDS_H__
#define __MC_COMMANDS_H__

#include <stdint.h>

class mc_commands{

  public:

    mc_commands();

    ~mc_commands();

    void run_command(uint8_t);

    enum command_types{

      NO_CMD = 0,

      //board logging controls
      START_SURG_CMD = 1,
      STOP_SURG_CMD = 2,
      CLEAR_BOARD_CMD = 3,

      //menu controls
      MENU_UP_CMD = 4,
      MENU_DOWN_CMD = 5,
      MENU_LEFT_CMD = 6,
      MENU_RIGHT_CMD = 7,
      MENU_ENTER_CMD = 8

    };



  private:




};


#endif