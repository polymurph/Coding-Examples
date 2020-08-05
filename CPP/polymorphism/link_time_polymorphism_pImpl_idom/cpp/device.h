#ifndef _DRIVER_H_
#define _DRIVER_H_

namespace Drivers {
    
class Impl;
class Device
{
    public:
    Device();
    ~Device();

    void doSomething();
    void countUp();
    unsigned int getCounter();


    private:
    Impl* pImpl;
};

}
#endif // _DRIVER_H_