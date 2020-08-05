#include "device.h"
#include <iostream>


namespace Drivers{
using namespace std;

struct Impl
{
    unsigned int counter;
};

static Impl imp;

Device::Device()
{
    cout << "ctor Device::Device()" << endl;
    pImpl = &imp;
    pImpl->counter = 0;
}

Device::~Device()
{
    cout << "dtor Device::~Device()" << endl;
}

void Device::countUp()
{
    pImpl->counter++;
}

unsigned int Device::getCounter()
{
    return pImpl->counter;
}

void Device::doSomething()
{
    cout << "Device::doSomething()" << endl;
}
    
}