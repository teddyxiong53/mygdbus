.PHONY: all clean
CSRC := $(wildcard *.c)
OBJ := $(CSRC:.c=.o)
CFLAGS := $(shell pkg-config --cflags glib-2.0)
CFLAGS += $(shell pkg-config --cflags dbus-1)
LDFLAGS := $(shell pkg-config --libs glib-2.0 dbus-1)
all:$(OBJ)
	gcc $(CFLAGS) $^ -o test $(LDFLAGS)
