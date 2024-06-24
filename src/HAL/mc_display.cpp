//Platform includes


//Local includes
#include "HAL/include/mc_display.h"
#include <Arduino.h>


//External variables


GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT> edisplay(GxEPD2_420_GDEY042T81(/*CS=5*/ 26, /*DC=*/ 25, /*RST=*/ 33, /*BUSY=*/ 32)); //GDEY042T81, 400x300, SSD1683 (no inking)

SPIClass hspi(HSPI);





mc_display::mc_display(){



}

mc_display::~mc_display(){


    
}


void mc_display::init(){


  hspi.begin(/*SCK*/14, /*MISO*/12, /*MOSI*/13, /*SS*/26);
  edisplay.epd2.selectSPI(hspi, SPISettings(4000000, MSBFIRST, SPI_MODE0));

  edisplay.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
  


  //init screen
  edisplay.setRotation(0);
  edisplay.setFont(&FreeMonoBold9pt7b);
  // if (display.epd2.WIDTH < 104) display.setFont(0);
  edisplay.setTextColor(GxEPD_BLACK);
  // int16_t tbx, tby; uint16_t tbw, tbh;
  // display.getTextBounds(init_text, 0, 0, &tbx, &tby, &tbw, &tbh);

  // // center bounding box by transposition of origin:
  // uint16_t x = ((display.width() - tbw) / 2) - tbx;
  // uint16_t y = ((display.height() - tbh) / 2) - tby;

  edisplay.setFullWindow();
  edisplay.firstPage();
  

  edisplay.setPartialWindow(0, 0, edisplay.width(), edisplay.height());

  do
  {
    edisplay.fillScreen(GxEPD_WHITE);
    
    edisplay.setCursor(140, 150);
    edisplay.print("Boot screen");

    edisplay.setCursor(60, 200);
    edisplay.print("Mediclinic logo goes here");
  }
  while (edisplay.nextPage());



}


//local variables