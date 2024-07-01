#ifndef __TYPES_H__
#define __TYPES_H__






enum mc_system_states{
  STATE_INIT = 0,
  STATE_WAITING_FOR_NETWORK = 1,
  STATE_NETWORK_CONNECTING = 2,
  STATE_IDLE = 3,
  STATE_SURGERY_BUSY = 4,
  STATE_UPLOAD_DATA = 5,
  STATE_POWER_DOWN = 6
};


#define QUEUE_ELEMENT_SIZE  50
#define QUEUE_STRING_LENGTH  100
typedef struct {
  char string[QUEUE_STRING_LENGTH];
} message_t;





  enum display_char_type{
    TEXT_ARRAY,
    BITMAP_ARRAY
  };



typedef struct{
   unsigned char* item;
   uint8_t item_type;
   uint16_t width;
   uint16_t height;
}display_item;



typedef struct{
  display_item item;
  uint16_t start_x;
  uint16_t start_y;

}display_group;



#endif