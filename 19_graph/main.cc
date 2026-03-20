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

    std::cout << std::endl;
    std::cout << "BFS:" << std::endl;
    g.BFS('a');
    std::cout << "DFS:" << std::endl;
    g.DFS('a');

    std::cout << "------------------------------" << std::endl;
    Graph<char, int> x("abcdefghi", 9);
    x.AddEdge('a', 'b', 4);
    x.AddEdge('a', 'h', 8);
    //g.AddEdge('a', 'h', 9);
    x.AddEdge('b', 'c', 8);
    x.AddEdge('b', 'h', 11);
    x.AddEdge('c', 'i', 2);
    x.AddEdge('c', 'f', 4);
    x.AddEdge('c', 'd', 7);
    x.AddEdge('d', 'f', 14);
    x.AddEdge('d', 'e', 9);
    x.AddEdge('e', 'f', 10);
    x.AddEdge('f', 'g', 2);
    x.AddEdge('g', 'h', 1);
    x.AddEdge('g', 'i', 6);
    x.AddEdge('h', 'i', 7);

    Graph<char, int> minTree;
    std::cout << "Kruskal min tree:  " << x.MinTreeKruskal(minTree) << std::endl;
    minTree.Print();

    std::cout << "------------------------------" << std::endl;
    const char* str = "syztx";
    Graph<char, int, INT_MAX, true> y(str, strlen(str));
    y.AddEdge('s', 't', 10);
    y.AddEdge('s', 'y', 5);
    y.AddEdge('y', 't', 3);
    y.AddEdge('y', 'x', 9);
    y.AddEdge('y', 'z', 2);
    y.AddEdge('z', 's', 7);
    y.AddEdge('z', 'x', 6);
    y.AddEdge('t', 'y', 2);
    y.AddEdge('t', 'x', 1);
    y.AddEdge('x', 'z', 4);

    std::vector<int> dist;
    std::vector<int> parentPath;
    y.Dijkstra('s', dist, parentPath);
    std::cout << "Dijkstra shortest path:  " << std::endl;
    y.Print();
    std::cout << std::endl;
    std::cout << "Define s as start node" << std::endl;
    y.PrintShortPath('s', dist, parentPath);
}