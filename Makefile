CC=clang
OPTS=-Wall -pedantic
LIBS=-lstdc++
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

APPFILE=dateformatter

all: $(APPFILE)

$(APPFILE): $(OBJECTS)
	$(CC) $(LIBS) -o $@ $^

.cpp.o:
	$(CC) -c $(OPTS) $<

clean:
	rm $(APPFILE) $(OBJECTS)

install:
	cp $(APPFILE) /usr/local/bin/

uninstall:
	rm /usr/local/bin/$(APPFILE)
