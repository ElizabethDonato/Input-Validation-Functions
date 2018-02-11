CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = ValidInt.o ValidDouble.o Menu.o UserInput.o
SRCS = main.cpp

all: ValidInt ValidDouble Menu UserInput main

ValidInt: ValidInt.hpp ValidInt.cpp
        ${CXX} ${CXXFLAGS} ValidInt.cpp -c

ValidDouble: ValidDouble.hpp ValidDouble.cpp
        ${CXX} ${CXXFLAGS} ValidDouble.cpp -c

Menu: ValidInt.hpp Menu.hpp ValidInt.cpp Menu.cpp
        ${CXX} ${CXXFLAGS} ValidInt.cpp Menu.cpp -c

UserInput: UserInput.hpp UserInput.cpp
        ${CXX} ${CXXFLAGS} UserInput.cpp -c

main: ${OBJS}
        ${CXX} ${CXXFLAGS} ${OBJS} ${SRCS} -o main

val:
        valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes ./main

clean:
        rm -f *.o main

