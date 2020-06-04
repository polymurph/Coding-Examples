#include "../../include/driver/driver.h"
#include<stdint.h>
#include <iostream>


using namespace std;

#if 0
Driver::Driver(spi_trx_t spi_trx) : spi_trx(spi_trx)
{
    cout << "Ctor: Driver"<<endl;
}
Driver::Driver(_Bind a) : a(a)
{
    cout << "Ctor: Driver"<<endl;
}
#endif

Driver::Driver(cb_t trx) : trx(trx)
{
    cout << "Ctor: Driver"<<endl;
}

void Driver::do_someting()
{
    cout << "Driver::do_something()" << endl;
    cout << "   writing 0x01 to spi_trx" << endl;
    //spi_trx(0x01);

    trx(0x01);
}