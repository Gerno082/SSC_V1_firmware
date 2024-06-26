
#include <SPI.h>
#include "FS.h"
#include "SD.h"
#include "HAL/include/mc_sd.h"

#include "main.h"


mc_sd::mc_sd(){



}

mc_sd::~mc_sd(){


    
}


void mc_sd::init(SPIClass* spi_bus){


    if(!SD.begin(SD_CS_PIN, *spi_bus)){
        Serial.println("Card Mount Failed");
        return;
    }else{
        Serial.println("Card Mount success");
    }

    uint8_t cardType = SD.cardType();

    if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
        return;
    }

    Serial.print("SD Card Type: ");

    if(cardType == CARD_MMC){
        Serial.println("MMC");
    } else if(cardType == CARD_SD){
        Serial.println("SDSC");
    } else if(cardType == CARD_SDHC){
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);

}




void mc_sd::readfile(fs::FS &fs, const char * path){


  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
  if(!file){
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.print("Read from file: ");
  while(file.available()){
    Serial.write(file.read());
  }
  file.close();

}

