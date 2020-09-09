#ifndef _FOO_H_
#define _FOO_H_

#include <functional>
#include <stdint.h>

class Foo{
    public:
    typedef std::function<void(uint8_t, uint8_t, bool)> set_pixel_cb_t;

    Foo(set_pixel_cb_t cb) :
        set_pixel(cb)
    {
        
    }

    void do_something()
    {
        set_pixel(1,2,false);
    }

    private:

    set_pixel_cb_t set_pixel;

};

#endif // _FOO_H_