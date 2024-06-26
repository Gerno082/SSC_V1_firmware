#ifndef __MC_SD_H__
#define __MC_SD_H__


#include "FS.h"


class mc_sd{

  public:

    mc_sd();

    ~mc_sd();

    void init(SPIClass* spi_bus);


    void readfile(fs::FS &fs, const char * path);

  private:






};




#endif  //__MC_SD_H__