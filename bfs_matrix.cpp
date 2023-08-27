#include <iostream>
#include "list.h"

using namespace std;

class Graph {
private:
    int numVertices;
    List<int>::dynamicArray* adjacencyMatrix;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjacencyMatrix = new List<int>::dynamicArray[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i].addArray(0); // Initialize with 0 indicating no edge
        }
    }

    void addEdge(int source, int destination) {
        adjacencyMatrix[source].arr[destination] = 1;
    }

    void BFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        List<int>::queue q;
        visited[startVertex] = true;
        q.enqueue(startVertex);

        cout << "Breadth First Traversal starting from vertex " << startVertex << ": ";

        while (q.head) {
            int currentVertex = q.dequeue();
            cout << currentVertex << " ";

            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[currentVertex].arr[i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.enqueue(i);
                }
            }
        }

        delete[] visited;
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // Perform BFS traversal starting from vertex 0
    graph.BFS(0);

    return 0;
}
