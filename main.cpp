#include <iostream>
#include "WeightedGraph.h"

using namespace std;

int main() {
    WeightedGraph graph(5);

    Vertex* A = new Vertex("A");
    Vertex* B = new Vertex("B");
    Vertex* C = new Vertex("C");
    Vertex* D = new Vertex("D");
    Vertex* E = new Vertex("E");

    graph.addVertex(A);
    graph.addVertex(B);
    graph.addVertex(C);
    graph.addVertex(D);
    graph.addVertex(E);

    graph.addEdge(0, 3, 60);
    graph.addEdge(0, 2, 12);
    graph.addEdge(1, 0, 10);
    graph.addEdge(2, 3, 32);
    graph.addEdge(2, 1, 20);
    graph.addEdge(4, 0, 7);

    cout << "DFS from E:" << endl;
    graph.DFS(E);

    cout << endl << "BFS from E:" << endl;
    graph.BFS(E);

    cout << endl << "Finding path from E to D:" << endl;
    graph.findPath(E, D);

    cout << endl << "Finding path from D to A:" << endl;
    graph.findPath(D, A);

    return 0;
}