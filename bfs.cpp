#include "List.h"
#include <iostream>
#include <memory>

template <class T>
class Graph {
    int numVertices;
    typename List<T>::doublyLl *adjLists;
    bool *visited;

public:
    Graph(T vertices);
    void addEdge(T src, T dest);
    void BFS(T startVertex) const;
};

template <class T>
Graph<T>::Graph(T vertices) : numVertices(vertices) {
    adjLists = new typename List<T>::doublyLl[vertices];
    visited = new bool[vertices];
}

template <class T>
void Graph<T>::addEdge(T src, T dest) {
    adjLists[src].addElement(dest);
    adjLists[dest].addElement(src);
}

template <class T>
void Graph<T>::BFS(T startVertex) const {
    List<int>::queue queue;

    visited[startVertex] = true;
    queue.enqueue(startVertex);

    while (queue.head) {
        int currVertex = queue.head->data;
        std::cout << "Visited " << currVertex << " ";
        queue.deleteFirst();

        typename List<int>::doublyLl::Node *i;

        for (i = adjLists[currVertex].head; i != nullptr; i = i->next) {
            int adjVertex = i->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.enqueue(adjVertex);
            }
        }
    }
}

int main() {
    Graph<int> g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    std::cin.get();

    return 0;
}
