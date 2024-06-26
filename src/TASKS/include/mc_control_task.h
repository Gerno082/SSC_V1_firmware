#ifndef __MC_CONTROL_TASK_H__
#define __MC_CONTROL_TASK_H__

void control_task_init(SPIClass* spi_bus);

void control_task_periodic_execute();

#endif  //__MC_HARDWARE_TASK_H__