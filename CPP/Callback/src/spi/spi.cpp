#include"../../include/spi/spi.h"

#include<stdint.h>
#include<iostream>

using namespace std;


uint8_t SPI::trx(uint8_t data)
{
    cout <<"SPI::trx."<<endl;
    cout <<"    recived:    0x" << hex << unsigned(data) << dec << endl;
    cout <<"    returning:  0xAE"<<endl;
    return 0xAE;
}