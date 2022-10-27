##########################################################
# Created by: Lalit Vats                                  #
# Created on: Monday 24 October 2022 12:27:59 PM IST #
##########################################################


SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
REPORTDIR = ../reports
CFLAGS = -c -g -Wall -I${INCLUDEDIR} -I../external/include -DLOG_USE_COLOR




all:

	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/crud.c -o ${OBJDIR}/crud.o
	gcc ${CFLAGS}  ${SRCDIR}/listMgmt.c -o ${OBJDIR}/listMgt.o
	gcc ${CFLAGS}  ${SRCDIR}/utility.c -o ${OBJDIR}/utility.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/crud.o ${OBJDIR}/utility.o ${OBJDIR}/listMgt.o -o ${BINDIR}/Project.bin

memcheck:
	valgrind ${BINDIR}/Project.bin > ${REPORTDIR}/memcheck.txt 

clean:

	rm ${OBJDIR}/main.o ${BINDIR}/Project.bin  ${OBJDIR}/crud.o ${OBJDIR}/listMgt.o ${OBJDIR}/utility.o


#################### End of Makefile #####################
