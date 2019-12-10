CXX = g++

CXXFLAGS = -g

BINARY = hw13

TARFILE = hw13.tar

all: $(BINARY)

$(BINARY):
	$(CXX) $(CXXFLAGS) hw13.cpp -o $(BINARY)
clean:
	rm -rf $(BINARY) $(TARFILE)
tar:
	tar cf $(TARFILE) Makefile hw13.scr hw13.cpp queue.h