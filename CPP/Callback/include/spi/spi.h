#ifndef _SPI_H_
#define _SPI_H_

#include<stdint.h>
#include<iostream>
using namespace std;

class SPI
{
    public:

    SPI()
    {
        cout << "Ctor: SPI" << endl;
    }
    uint8_t trx(uint8_t data);

    private:

};

#endif // _SPI_H_