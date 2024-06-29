#ifndef __MC_WIFI_TASK_H__
#define __MC_WIFI_TASK_H__

#define DEFAULT_SSID        "JH12-2"
#define DEFAULT_PASSWORD    "#Merida124501"

#define WIFI_CONNECTION_CHECK_RATE      3000   //in milliseconds, Check the WiFi connection every at this interval

#define WIFI_START_CONNECTION_TIMEOUT   10000   //in milliseconds, the timeout when starting the WiFi connection

void wifi_task_init();

void wifi_task_periodic_execute();



void restart_wifi();

void check_wifi_connection(unsigned long);

#endif  //__MC_WIFI_TASK_H__