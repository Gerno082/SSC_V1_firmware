#ifndef __MC_12864_LCD_H__
#define __MC_12864_LCD_H__


#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include "types.h"





class mc_display{

  public:

    mc_display();

    ~mc_display();

    void init(SPIClass* spi_bus);

    void connecting_screen();

    void idle_screen();

    void surgery_screen();

    void upload_screen();




    // char* time_arr[] = {""};
    // char* date_arr[] = {""};


    // String timestr = "21:12";
    // String datestr = "25-JUN";








};


#endif  //__MC_12864_LCD_H__