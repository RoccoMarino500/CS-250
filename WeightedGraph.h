#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Vertex {
public:
    Vertex(string title) : m_title(title) {}
    string getTitle() { return m_title; }

private:
    string m_title;
};

class WeightedGraph {
public:
    WeightedGraph(int size);
    void addVertex(Vertex* aVertex);
    void addEdge(int fromVertex, int toVertex, int weight);
    void DFS(Vertex* aVertex);
    void BFS(Vertex* aVertex);
    void findPath(Vertex* source, Vertex* destination);

private:
    static const int NULL_EDGE;
    int m_numVertices;
    int m_maxVertices;
    vector<Vertex*> m_vertices;
    vector<vector<int>> m_edges;
    vector<bool> m_marks;

    void clearMarks();
    void doDFS(Vertex* aVertex, vector<string>& path, int& cost);
    void doBFS(Vertex* aVertex, vector<string>& path, int& cost);
    int indexIs(Vertex* aVertex);
};

#endif