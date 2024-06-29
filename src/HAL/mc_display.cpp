//Platform includes
#include <Arduino.h>
#include <SPI.h>

//Local includes
#include "HAL/include/mc_display.h"



#include "main.h"

#include "images.h"


//External variables


GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT> edisplay(GxEPD2_420_GDEY042T81(/*CS=5*/ 26, /*DC=*/ 25, /*RST=*/ 33, /*BUSY=*/ 32)); //GDEY042T81, 400x300, SSD1683 (no inking)







mc_display::mc_display(){



}

mc_display::~mc_display(){


    
}






void mc_display::init(SPIClass* spi_bus){

  #ifdef DEBUG_DISPLAY
    Serial.println("Display init");
  #endif

  
  
  edisplay.epd2.selectSPI(*spi_bus, SPISettings(4000000, MSBFIRST, SPI_MODE0));

  edisplay.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
  


  //init screen
  edisplay.setRotation(0);
  edisplay.setFont(&FreeMonoBold24pt7b);
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

  // do
  // {
  //   edisplay.fillScreen(GxEPD_WHITE);
    
  //   edisplay.setCursor(50, 150);
  //   edisplay.print("Boot");

  //   edisplay.setCursor(10, 200);
  //   edisplay.print("Mediclinic");
  // }
  // while (edisplay.nextPage());

  // edisplay.hibernate();




  do
  {
    edisplay.fillScreen(GxEPD_WHITE);
    edisplay.drawXBitmap(0,0,MCBoot,400,300,GxEPD_BLACK); 
  }
  while (edisplay.nextPage());
  edisplay.hibernate();

  vTaskDelay(3000/portTICK_PERIOD_MS);

  do
  {
    edisplay.fillScreen(GxEPD_WHITE);
    edisplay.drawXBitmap(0,0,InnovaticsBoot,400,300,GxEPD_BLACK); 
  }
  while (edisplay.nextPage());
  edisplay.hibernate();


  vTaskDelay(2000/portTICK_PERIOD_MS);




}




void mc_display::connecting_screen(){

  #ifdef DEBUG_DISPLAY
    Serial.println("Display Show connecting screen");
  #endif


  do
  {
    edisplay.fillScreen(GxEPD_WHITE);
    
    edisplay.setCursor(10, 100);
    edisplay.print("Connecting");

    edisplay.setCursor(10, 180);
    edisplay.print("to Wifi");
  }
  while (edisplay.nextPage());

  edisplay.hibernate();


}





void mc_display::idle_screen(){

  #ifdef DEBUG_DISPLAY
    Serial.println("Display Show idle screen");
  #endif


  do
  {
    edisplay.fillScreen(GxEPD_WHITE);
    
    edisplay.setCursor(10, 100);
    edisplay.print("IDLE State");
  }
  while (edisplay.nextPage());

  edisplay.hibernate();



}


void mc_display::surgery_screen(){

  #ifdef DEBUG_DISPLAY
    Serial.println("Display Show surgery screen");
  #endif


  do
  {
    edisplay.fillScreen(GxEPD_WHITE);
    
    edisplay.setCursor(10, 100);
    edisplay.print("Surgery");
  }
  while (edisplay.nextPage());

  edisplay.hibernate();



}



void mc_display::upload_screen(){

  #ifdef DEBUG_DISPLAY
    Serial.println("Display Show upload screen");
  #endif


  do
  {
    edisplay.fillScreen(GxEPD_WHITE);
    
    edisplay.setCursor(10, 100);
    edisplay.print("Uploading");
  }
  while (edisplay.nextPage());

  edisplay.hibernate();

}

//local variables