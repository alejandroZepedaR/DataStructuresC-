//This program defines a Graph class with a constructor that takes the number of nodes in the graph
//and an adjacency list to store the edges. The AddEdge function adds an edge to the graph by adding
//an entry to the adjacency list for the from node.
//The DepthFirstTraversal function performs a depth first traversal of the graph,
//starting at the specified start_node. It marks the start_node as visited, prints it,
//and then recursively performs a depth first traversal on each of its unvisited neighbors.
#include <iostream>
#include <vector>

class Graph {
 public:
  Graph(int num_nodes) : adjacency_list_(num_nodes) {}

  void AddEdge(int from, int to) {
    adjacency_list_[from].push_back(to);
  }

  void DepthFirstTraversal(int start_node, std::vector<bool>& visited) {
    visited[start_node] = true;
    std::cout << start_node << " ";

    for (int neighbor : adjacency_list_[start_node]) {
      if (!visited[neighbor]) {
        DepthFirstTraversal(neighbor, visited);
      }
    }
  }

 private:
  std::vector<std::vector<int>> adjacency_list_;
};

int main() {
  Graph g(5);
  g.AddEdge(0, 1);
  g.AddEdge(0, 2);
  g.AddEdge(1, 3);
  g.AddEdge(1, 4);

  std::vector<bool> visited(5, false);
  g.DepthFirstTraversal(0, visited);

  return 0;
}
