#include "matrix_graph.hpp"
using namespace MatrixGraphModule;

int main()
{
    Graph<char, int, INT_MAX, true> g("abcd", 4);
    g.AddEdge('a', 'b', 1);
    g.AddEdge('a', 'd', 4);
    g.AddEdge('b', 'd', 2);
    g.AddEdge('b', 'c', 9);
    g.AddEdge('c', 'd', 8);
    g.AddEdge('c', 'b', 5);
    g.AddEdge('c', 'a', 3);
    g.AddEdge('d', 'c', 6);
    
    g.Print();
}