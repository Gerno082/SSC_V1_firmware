#ifndef __MC_DISPLAY_TASK_H__
#define __MC_DISPLAY_TASK_H__

#include <SPI.h>

void display_task_init(SPIClass* spi_bus);

void display_task_periodic_execute();

#endif  //__MC_DISPLAY_TASK_H__