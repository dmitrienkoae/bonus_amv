all: superstr

superstr: main.o overlap_graph.o solution.o
    g++ main.o overlap_graph.o solution.o -o str

main.o: main.cpp
    g++ -c main.cpp

overlap_graph.o: overlap_graph.cpp overlap_graph.hpp
    g++ -c overlap_graph.cpp

solution.o: solution.cpp
    g++ -c solution.cpp

clean:
    rm -rf *.o hello
