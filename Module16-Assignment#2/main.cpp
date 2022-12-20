#include <iostream>
#include <vector>
#include <queue>

class Graph {
 public:
  Graph(int num_nodes) : adjacency_list_(num_nodes) {}

  void AddEdge(int from, int to) {
    adjacency_list_[from].push_back(to);
  }

  void BreadthFirstTraversal(int start_node) {
    std::vector<bool> visited(adjacency_list_.size(), false);
    std::queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty()) {
      int current_node = q.front();
      q.pop();
      std::cout << current_node << " ";

      for (int neighbor : adjacency_list_[current_node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
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

  g.BreadthFirstTraversal(0);

  return 0;
}
