cpp_src = $(wildcard *.cpp) $(wildcard cpp/*.cpp)  
#c_src = $(wildcard driver/pf8574/*.c) $(wildcard ../c/algorithms/*.c) $(wildcard driver/ma120x0/*.c)
#c_src = $(wildcard ../c/algorithms/*.c) $(wildcard driver/ma120x0/*.c)
c_src = $(wildcard c/*.c)


cpp_obj = $(cpp_src:.cpp=.o)
c_obj = $(c_src:.c=.o)
CC = g++ 
CFLAGS = -Wall -pedantic  
LDFLAGS = 
EXEC = runtest


all : $(EXEC)

$(EXEC): $(cpp_obj) $(c_obj)
	$(CC) -o $@ $^ $(LDFLAGS) 
 
clean: 
	rm -rf $(c_obj) $(cpp_obj) $(EXEC)
	#del *.o, *.exe

cleanall: 
	rm -rf $(c_obj) $(cpp_obj) $(EXEC)