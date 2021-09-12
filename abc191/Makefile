CXX		= g++
CXXFLAGS	= -std=gnu++17 -O2 -Wall

all:
	make $(patsubst %.cpp,%,$(wildcard *.cpp))

%: %.cpp
	time $(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(patsubst %.cpp,%,$(wildcard *.cpp))
