#include "device.h"
#include <iostream>

using namespace Drivers;
using namespace std;

int main(void)
{
   static Device device;

    device.doSomething();

    device.countUp();

    cout << device.getCounter() << endl;


    return 0;
}