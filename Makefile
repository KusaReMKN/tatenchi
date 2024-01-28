TARGET=	tatenchi
OBJS=	tatenchi.o

SHELL=	/bin/sh
CXX=	c++
CXXFLAGS=	-O2 -Wall
RM=	rm -f

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
