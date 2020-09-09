#include <iostream>

#include <functional>
#include <stdint.h>

#include "foo.h"
#include "baa.h"

using namespace std;
using namespace std::placeholders; // for `_1`

int main(void)
{
	
	Baa B;
	Foo A(bind(&Baa::baa_function, B, _1, _2, _3));

	A.do_something();

	cout << "Hello, World!" << endl;
	return 0;
}
