all: superstr

superstr: main.o overlap_graph.o solution.o FSM.o
    g++ main.o overlap_graph.o solution.o FSM.o -o str

main.o: main.cpp
    g++ -c main.cpp

FSM.o: FSM.cpp FSM.h
    g++ -c FSM.cpp

overlap_graph.o: overlap_graph.cpp overlap_graph.hpp FSM.cpp
    g++ -c overlap_graph.cpp

solution.o: solution.cpp
    g++ -c solution.cpp

clean:
    rm -rf *.o superstr
