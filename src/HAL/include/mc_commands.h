#ifndef __MC_COMMANDS_H__
#define __MC_COMMANDS_H__

#include <stdint.h>

class mc_commands{

  public:

    mc_commands();

    ~mc_commands();

    void run_command(uint8_t);

    enum command_types{

      NO_COMMAND,

      //board logging controls
      START_SURGERY_COMMAND,
      STOP_SURGERY_COMMAND,
      CLEAR_BOARD_COMMAND,

      //menu controls
      MENU_UP_COMMAND,
      MENU_DOWN_COMMAND,
      MENU_LEFT_COMMAND,
      MENU_RIGHT_COMMAND,
      MENU_ENTER_COMMAND

    };



  private:




};


#endif