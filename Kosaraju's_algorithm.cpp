#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "List.h"  // Include the provided header file

using namespace std;

// Define a directed graph class
class DirectedGraph {
private:
    int V;  // Number of vertices
    List<int>::singlyLl* adjList;  // Adjacency list

public:
    DirectedGraph(int vertices) : V(vertices) {
        adjList = new List<int>::singlyLl[V];
    }

    void addEdge(int src, int dest) {
        adjList[src].addElement(dest);
    }

    // Function to perform DFS on the graph
    void DFS(int vertex, vector<bool>& visited, stack<int>& Stack) {
        visited[vertex] = true;

        // Visit all adjacent vertices
        List<int>::singlyLl::node* current = adjList[vertex].head;
        while (current) {
            int neighbor = current->data;
            if (!visited[neighbor]) {
                DFS(neighbor, visited, Stack);
            }
            current = current->ptr;
        }

        // Push the current vertex to the stack when done
        Stack.push(vertex);
    }

    // Function to find strongly connected components using Kosaraju's algorithm
    vector<vector<int>> kosaraju() {
        vector<bool> visited(V, false);
        stack<int> Stack;

        // Step 1: Perform DFS and fill the stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, visited, Stack);
            }
        }

        // Create a transpose graph
        DirectedGraph transpose(V);
        for (int i = 0; i < V; i++) {
            List<int>::singlyLl::node* current = adjList[i].head;
            while (current) {
                int neighbor = current->data;
                transpose.addEdge(neighbor, i);  // Reverse edges
                current = current->ptr;
            }
        }

        // Step 2: Perform DFS on the transpose graph using the stack
        vector<vector<int>> stronglyConnectedComponents;
        fill(visited.begin(), visited.end(), false);  // Reset visited array

        while (!Stack.empty()) {
            int vertex = Stack.top();
            Stack.pop();

            if (!visited[vertex]) {
                vector<int> component;
                transpose.DFS(vertex, visited, component);
                stronglyConnectedComponents.push_back(component);
            }
        }

        return stronglyConnectedComponents;
    }
};

int main() {
    DirectedGraph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    // Find strongly connected components using Kosaraju's algorithm
    vector<vector<int>> scc = graph.kosaraju();

    // Print the strongly connected components
    cout << "Strongly Connected Components:\n";
    for (const vector<int>& component : scc) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
