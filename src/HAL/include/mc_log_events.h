#ifndef __MC_LOG_EVENT_H__
#define __MC_LOG_EVENT_H__

//Platform includes
#include <stdint.h>
#include <Arduino.h>

//Local includes
#include "HAL/include/mc_commands.h"
#include "HAL/include/mc_database.h"

//external objects definition 
extern mc_commands commands;



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
      CHECKED_NA = 3
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
      ITEM_TYPE_TRI_STATE = 1
    };

    typedef struct{
      uint8_t type;
      uint8_t column;
      uint8_t state;
      uint8_t btn[2];
      uint8_t command[2];
    }  item_map_layer;


    item_map_layer ITEMS[24] = {
      //Column 1 buttons (8 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    1        /*Buttons*/,   commands.NO_COMMAND},    //Sign in, 0
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    3        /*Buttons*/,   commands.NO_COMMAND},    //Identity
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    4        /*Buttons*/,   commands.NO_COMMAND},    //Procedure
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    5        /*Buttons*/,   commands.NO_COMMAND},    //site
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    6        /*Buttons*/,   commands.NO_COMMAND},    //consent
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    7        /*Buttons*/,   commands.NO_COMMAND},    //allergies
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    {9,10}   /*Buttons*/,   commands.NO_COMMAND},    //site marked
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    0  /*Column*/,    UNCHECKED  /*Item_state*/,    {12,13}  /*Buttons*/,   commands.NO_COMMAND},     //blood on standby, 7

      //Column 2 buttons (9 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    1        /*Buttons*/,   commands.NO_COMMAND},    //Time Out, 8
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    3        /*Buttons*/,   commands.NO_COMMAND},    //Introduce team members
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    5        /*Buttons*/,   commands.NO_COMMAND},    //Patient identity
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    6        /*Buttons*/,   commands.NO_COMMAND},    //Procedure
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    7        /*Buttons*/,   commands.NO_COMMAND},    //Site
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    8        /*Buttons*/,   commands.NO_COMMAND},    //Sterility of instruments
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    9        /*Buttons*/,   commands.NO_COMMAND},    //Confirm any implants
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    11       /*Buttons*/,   commands.NO_COMMAND},    //anticipated critical events
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    1  /*Column*/,    UNCHECKED  /*Item_state*/,    {13,14}  /*Buttons*/,   commands.NO_COMMAND},     //Antibiotic prophylaxis, 16

      //Column 3 buttons (7 items)
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    1        /*Buttons*/,   commands.NO_COMMAND},    //Sign out, 17 
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    3        /*Buttons*/,   commands.NO_COMMAND},    //Surgeon confirm procedure name
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    5        /*Buttons*/,   commands.NO_COMMAND},    //swabs
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    6        /*Buttons*/,   commands.NO_COMMAND},    //sharps
      { ITEM_TYPE_DUAL_STATE  /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    7        /*Buttons*/,   commands.NO_COMMAND},    //isntruments counted
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {9,10}   /*Buttons*/,   commands.NO_COMMAND},    //Specimen is labelled
      { ITEM_TYPE_TRI_STATE   /*Item type*/,    2  /*Column*/,    UNCHECKED  /*Item_state*/,    {12,13}  /*Buttons*/,   commands.NO_COMMAND}    //equipment issues reported, 23
    };



    String item_strings[24] = {
      //Column 1 buttons (8 items)
      "Sign_in",//Sign in, 0
      "ID",//Identity
      "Proc",//Procedure
      "Site",//site
      "Consent",//consent
      "Allergies",//allergies
      "Site_mark",//site marked
      "Blood_standby",//blood on standby

      //Column 2 buttons (9 items)
      "Time_out",//Time Out
      "Intro_Team",//Introduce team members
      "Patient_ID",//Patient identity
      "Procedure_2",//Procedure
      "Site",//Site
      "Sterility",//Sterility of instruments
      "Confrim_impl",//Confirm any implants
      "Anticipated_events",//anticipated critical events
      "Antibiotic_prohpy",//Antibiotic prophylaxis, 16

      //Column 3 buttons (7 items)
      "Sign_out",//Sign out
      "Surgeon_confirm",//Surgeon confirm procedure name
      "Swabs",//swabs
      "Sharps",//sharps
      "instruments_count",//isntruments counted
      "Specimen_label",//Specimen is labelled
      "Equipment_issues"//equipment issues reported
    };


    #define CHECKED_STRING      "CHK"
    #define UNCHECKED_STRING    "UNCHK"
    #define CHECKED_YES_STRING  "CHKY"
    #define CHECKED_NA_STRING   "CHKNA"



    bool logging_enabled = true;


    #define BUTTON_BLOCK_TIME             100


    //A timer to block button presses for more than a predefined time
    unsigned long button_block_timer = 0;



  private:




};











#endif  //__MC_LOG_EVENT_H__