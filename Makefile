
CFLAGS = -c -Wall -std=c11 -g

LDFLAGS = -lm

SRCS= main.c functions.c

OBJS = main.o functions.o

FL_OPT=

FL =

ifeq ($(BODY), asm)
	FL = -DASSEMBLER
	SRCS += func_asm.s
	OBJS += func_asm.o
endif

ifeq ($(OPT), o0)
	CFLAGS += -o0
endif

ifeq ($(OPT), o1)
	CFLAGS += -O1
endif

ifeq ($(OPT), o2)
	CFLAGS += -O2
endif

ifeq ($(OPT), o3)
	CFLAGS += -O3
endif

ifeq ($(OPT), ofast)
	CFLAGS += -Ofast
endif

all: grey $(SRCS)

grey: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o grey
main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o
functions.o: functions.c 
	$(CC) $(CFLAGS) $(FL) functions.c -o functions.o
func_asm.o: func_asm.s
	nasm -f elf64 -g func_asm.s -o func_asm.o
clean:
	rm -rf $(OBJS)
