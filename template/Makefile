CXX		= g++
CXXFLAGS	= -std=gnu++17 -O2 -Wall

%: %.cpp
	time $(CXX) $(CXXFLAGS) $<
	./a.out

clean:
	rm -f a.out
