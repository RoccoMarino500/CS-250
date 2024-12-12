#include "WeightedGraph.h"
#include <limits>
#include <algorithm>

const int WeightedGraph::NULL_EDGE = 0;

WeightedGraph::WeightedGraph(int size) {
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size, nullptr);
    m_edges.resize(size, vector<int>(size, NULL_EDGE));
    m_marks.resize(size, false);
}

void WeightedGraph::addVertex(Vertex* aVertex) {
    m_vertices[m_numVertices] = aVertex;
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight) {
    m_edges[fromVertex][toVertex] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex) {
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
    }
    return -1;
}

void WeightedGraph::clearMarks() {
    fill(m_marks.begin(), m_marks.end(), false);
}

void WeightedGraph::doDFS(Vertex* aVertex, vector<string>& path, int& cost) {
    int currentIndex = indexIs(aVertex);
    m_marks[currentIndex] = true;
    path.push_back(aVertex->getTitle());

    for (int i = 0; i < m_numVertices; i++) {
        if (m_edges[currentIndex][i] != NULL_EDGE && !m_marks[i]) {
            cost += m_edges[currentIndex][i];
            doDFS(m_vertices[i], path, cost);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex) {
    clearMarks();
    vector<string> path;
    int cost = 0;

    doDFS(aVertex, path, cost);

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << (i < path.size() - 1 ? " -> " : "");
    }
    cout << endl << "Cost: " << cost << endl;
}

void WeightedGraph::doBFS(Vertex* aVertex, vector<string>& path, int& cost) {
    queue<Vertex*> que;
    int startIndex = indexIs(aVertex);

    m_marks[startIndex] = true;
    que.push(aVertex);

    while (!que.empty()) {
        Vertex* current = que.front();
        que.pop();
        int currentIndex = indexIs(current);
        path.push_back(current->getTitle());

        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[currentIndex][i] != NULL_EDGE && !m_marks[i]) {
                m_marks[i] = true;
                cost += m_edges[currentIndex][i];
                que.push(m_vertices[i]);
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex) {
    clearMarks();
    vector<string> path;
    int cost = 0;

    doBFS(aVertex, path, cost);

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << (i < path.size() - 1 ? " -> " : "");
    }
    cout << endl << "Cost: " << cost << endl;
}

void WeightedGraph::findPath(Vertex* source, Vertex* destination) {
    vector<int> distance(m_numVertices, numeric_limits<int>::max());
    vector<int> previous(m_numVertices, -1);
    int startIndex = indexIs(source);
    int endIndex = indexIs(destination);

    distance[startIndex] = 0;

    for (int i = 0; i < m_numVertices; i++) {
        for (int u = 0; u < m_numVertices; u++) {
            for (int v = 0; v < m_numVertices; v++) {
                if (m_edges[u][v] != NULL_EDGE && distance[u] != numeric_limits<int>::max()) {
                    int newDist = distance[u] + m_edges[u][v];
                    if (newDist < distance[v]) {
                        distance[v] = newDist;
                        previous[v] = u;
                    }
                }
            }
        }
    }

    if (distance[endIndex] == numeric_limits<int>::max()) {
        cout << "No path from " << source->getTitle() << " to " << destination->getTitle() << endl;
        return;
    }

    vector<string> path;
    for (int at = endIndex; at != -1; at = previous[at]) {
        path.push_back(m_vertices[at]->getTitle());
    }
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << (i < path.size() - 1 ? " -> " : "");
    }
    cout << endl << "Length: " << distance[endIndex] << endl;
}