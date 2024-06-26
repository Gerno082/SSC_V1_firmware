#ifndef __MC_LOG_EVENT_H__
#define __MC_LOG_EVENT_H__

//Platform includes
#include <stdint.h>
#include <Arduino.h>

//Local includes
#include "HAL/include/mc_commands.h"
#include "HAL/include/mc_database.h"

//external objects definition 
extern mc_commands cmd;



class mc_items{

  public:

    mc_items();

    ~mc_items();

    void init();

    void log_item_check(uint8_t, uint8_t, uint8_t);

    void log_button_press(uint8_t, uint8_t, uint8_t);

    void log_item(uint8_t, uint8_t, uint8_t);

    

    mc_database database;


    enum item_states{
      UNCHECKED = 0,
      CHECKED = 1,
      CHECKED_YES = 2,
      CHECKED_NA = 3,
      CHECKED_L = 4,
      CHECKED_R = 5
    };




    //Columns enumeration
    enum columns2
    {
      LED_COL1 = 0,
      LED_COL2 = 1,
      LED_COL3 = 2,
      LED_COL4 = 3
    };


    enum item_button_states{
      BUTTON_PRESSED = 0,
      BUTTON_RELEASED = 1
    };

    enum item_types{
      ITEM_TYPE_DUAL_STATE = 0,
      ITEM_TYPE_TRI_STATE = 1,
      ITEM_TYPE_QUAD_STATE = 2
    };


    enum command_positions{
      UNCHECKED_COMMAND = 0,

      CHECKED_COMMAND = 1,
      YES_CHECKED_COMMAND = 1,
      L_CHECKED_COMMAND = 1,

      R_CHECKED_COMMAND = 2,

      NA_CHECKED_COMMAND = 3
      
    };


    typedef struct{
      uint8_t type;
      uint8_t column;
      uint8_t state;
      uint8_t btn[3];
      uint8_t command[4];
    }  item_map_layer;


    #define NB 0





    //cmd
    // - for Dual state:  {Unchecked command, Checked command, 0, 0}
    // - for Tri state:   {Unchecked command, YES command, N/A command, 0}
    // - for Quad state:  {Unchecked command, L command, R command, N/A command}


    item_map_layer ITEMS[23] = {
      //Column 1 buttons (8 items)                                                                                        //UNCHECKED         CHECKED/ YES(TRI)/ L(QUAD)    R(QUAD)             N/A(TRI/QUAD)          
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {0,NB,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.START_SURG_CMD,           cmd.NO_CMD,         cmd.NO_CMD}},    //Identity
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {2,NB,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Procedure
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {4,NB,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //site
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {6,NB,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //consent
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {8,NB,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //allergies
      { ITEM_TYPE_QUAD_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {10,11,12} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //side checked
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {14,15,NB} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //site marked
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,   {20,21,NB} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //blood on standby, 7

      //Column 2 buttons (8 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {0,NB,NB} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Introduce team members
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {4,NB,NB} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Patient identity
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {6,NB,NB} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Procedure
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {8,NB,NB} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Site
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {10,NB,NB}/*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Sterility of instruments
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {12,13,NB}/*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Confirm any implants
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {16,17,NB}/*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //anticipated critical events
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {20,21,NB}/*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Antibiotic prophylaxis, 15

      //Column 3 buttons (7 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {0,NB,NB} /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Surgeon confirm procedure name
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {4,5,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //swabs
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {6,7,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //sharps
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {8,9,NB}  /*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //isntruments counted
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {12,13,NB}/*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}},    //Specimen is labelled
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {16,17,NB}/*Buttons*/,   {cmd.NO_CMD,         cmd.STOP_SURG_CMD,            cmd.NO_CMD,         cmd.STOP_SURG_CMD}},//equipment issues reported
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {18,NB,NB}/*Buttons*/,   {cmd.NO_CMD,         cmd.NO_CMD,                   cmd.NO_CMD,         cmd.NO_CMD}}     //Log event button, 22
    };



    String button_names[23] = {
      //Column 1 buttons (8 items)
      "CONFIRM_ID",//Identity
      "CONFIRM_PROCEDURE",//Procedure
      "CONFIRM_SITE",//site
      "CONFIRM_CONSENT",//consent
      "CONFIRM_ALLERGIES",//allergies
      "SIDE_CHECKED",
      "SITE_MARKED",//site marked
      "BLOOD_STANDBY",//blood on standby

      //Column 2 buttons (9 items)
      "INTRODUCE_TEAM",//Introduce team members
      "SCRUB_CONFIRM_ID",//Patient identity
      "SCRUB_CONFIRM_PROCEDURE",//Procedure
      "SCRUB_CONFIRM_SITE",//Site
      "SCRUB_CONFIRM_STERILITY",//Sterility of instruments
      "SCRUB_CONFIRM_IMPLANTS",//Confirm any implants
      "ANTICIPATED_CRITICAL_EVENTS",//anticipated critical events
      "ANTIBIOTICS_PROPHYLAXIS",//Antibiotic prophylaxis, 16

      //Column 3 buttons (7 items)
      "SURGEON_CONFIRM_PROCEDURE",//Surgeon confirm procedure name
      "SCRUB_CONFIRM_SWABS",//swabs
      "SCRUB_CONFIRM_SHARPS",//sharps
      "SCRUB_CONFIRM_INSTRUMENTS",//isntruments counted
      "SPECIMEN_LABELLED",//Specimen is labelled
      "EQUIPMENT_ISSUES_REPORTED"//equipment issues reported
      "LOG_EVENT"
    };


    #define CHECKED_STRING      "CHK"
    #define UNCHECKED_STRING    "UNCHK"
    #define CHECKED_YES_STRING  "CHKY"
    #define CHECKED_NA_STRING   "CHKNA"
    #define CHECKED_L_STRING    "CHKL"
    #define CHECKED_R_STRING    "CHKR"



    bool logging_enabled = true;


    #define BUTTON_BLOCK_TIME             100


    //A timer to block button presses for more than a predefined time
    unsigned long button_block_timer = 0;



  private:




};











#endif  //__MC_LOG_EVENT_H__