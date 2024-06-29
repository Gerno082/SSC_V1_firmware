#ifndef __MC_SD_H__
#define __MC_SD_H__


#include "FS.h"


class mc_sd{

  public:

    mc_sd();

    ~mc_sd();

    void init(SPIClass* spi_bus);

    void listDir(fs::FS &fs, const char * dirname, uint8_t levels);

    void createDir(fs::FS &fs, const char * path);

    void removeDir(fs::FS &fs, const char * path);

    void readfile(fs::FS &fs, const char * path);

    void writeFile(fs::FS &fs, const char * path, const char * message);

    void appendFile(fs::FS &fs, const char * path, const char * message);

    void renameFile(fs::FS &fs, const char * path1, const char * path2);

    void deleteFile(fs::FS &fs, const char * path);

  private:






};




#endif  //__MC_SD_H__