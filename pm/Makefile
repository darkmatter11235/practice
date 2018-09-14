BOOST_ROOT = /home/prasanth/libs/boost_1_67_0

CXX :=/usr/bin/g++

CXXFLAGS :=-std=c++11 -I$(BOOST_ROOT)

#LDFLAGS := -L$(BOOST_ROOT)/libs -lpolygon
LDFLAGS := 

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

OBJECTS =  pm_test.o

pm: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

pm_test.o: 
	$(CXX) $(CXXFLAGS) -c pm_test.cpp -o pm_test.o

all:pm

clean:
	rm -rf pm *.o
