#include "main.h"
#include <iostream>
#include <array>
#include <functional>

#include "../include/spi/spi.h"
#include "../include/driver/driver.h"

using namespace std;
using namespace std::placeholders;

// https://stackoverflow.com/questions/35641437/c-pass-a-member-function-to-another-class
// https://stackoverflow.com/questions/26992834/setting-a-callback-function-which-is-non-static-member-function-of-a-class

#ifdef EXAMPLE

// the function using the function pointers:
void somefunction(void (*fptr)(void*, int, int), void* context) {
    fptr(context, 17, 42);
}

void non_member(void*, int i0, int i1) {
    std::cout << "I don't need any context! i0=" << i0 << " i1=" << i1 << "\n";
}

struct foo {
    void member(int i0, int i1) {
        std::cout << "member function: this=" << this << " i0=" << i0 << " i1=" << i1 << "\n";
    }
};

void forwarder(void* context, int i0, int i1) {
    static_cast<foo*>(context)->member(i0, i1);
}

int main() {
    somefunction(&non_member, 0);
    foo object;
    somefunction(&forwarder, &object);
}
#endif

#if 1

int main()
{
    // https://stackoverflow.com/questions/37607584/how-to-pass-a-stdbind-object-to-a-function
    // https://stackoverflow.com/questions/26992834/setting-a-callback-function-which-is-non-static-member-function-of-a-class
    cout << "start..." << endl;
    SPI spi_channel;

    auto func =bind(&SPI::trx, &spi_channel, _1);

    func(0xFF);


    //Driver device(func);

    Driver device(bind(&SPI::trx, &spi_channel, _1));

    device.do_someting();

    cout << "...end"<<endl;
    return 0;
}

#endif



#if 0
#include <iostream>
#include <string>
#include <functional>

using namespace std;

class MessageSource
{
       function<void(const string& msg)> _callback;

       template<typename A, typename B>
       void connect(A func_ptr, B obj_ptr)
       {
              _callback = bind(func_ptr, obj_ptr, placeholders::_1);
       }

       void send_msg(const string& msg)
       {
              if (_callback)
                     _callback(msg);
       }

       void disconnect()
       {
              _callback = nullptr;
       }
};

class Printer
{
       void print(const string& msg) { std::cout << msg << std::endl; };
};

int main()
{
       {
              Printer p;
              MessageSource s;
              s.connect(&Printer::print, &p);
              s.send_msg("test");
              s.disconnect();
              s.send_msg("test again");
       }

       system("pause");
       return 0;
}
#endif