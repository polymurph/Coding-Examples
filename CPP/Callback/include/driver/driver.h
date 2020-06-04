#ifndef _DRIVER_H_
#define _DRIVER_H_

#include<stdint.h>
#include<functional>

using namespace std;

// https://stackoverflow.com/questions/12662891/how-can-i-pass-a-member-function-where-a-free-function-is-expected


class Driver
{
    public:
    typedef uint8_t  (*spi_trx_t)(uint8_t);
    typedef function<uint8_t(uint8_t)> cb_t;

    //Driver(spi_trx_t spi_trx);
    Driver(cb_t trx);

    void do_someting();

    private:

    spi_trx_t spi_trx;
    cb_t trx;
};

#endif // _DRIVER_H_