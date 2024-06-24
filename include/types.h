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


#endif