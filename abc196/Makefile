CXX		= g++
CXXFLAGS	= -std=gnu++17 -O2 -Wall

%.o: %.cpp
	time $(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o
