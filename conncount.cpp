#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

typedef struct node {
  int data;
  int is_visited = 0;
  list<int> connected_node;
} node;

node *createNode(int data) {
  node *newNode = new node;
  newNode->data = data;
  return newNode;
}

unordered_map<int, node *> init(int n, int m) {
  unordered_map<int, node *> graph;
  unordered_map<int, int> existed_nodes;
  int in1, in2;

  for (int i = 0; i < m; i++) {
    cin >> in1 >> in2;
    if (existed_nodes[in1] != 1) {
      graph[in1] = createNode(in1);
      existed_nodes[in1] = 1;
    }

    if (existed_nodes[in2] != 1) {
      graph[in2] = createNode(in2);
      existed_nodes[in2] = 1;
    }

    graph[in1]->connected_node.push_back(in2);
    graph[in2]->connected_node.push_back(in1);
  }

  return graph;
}

void dfs(unordered_map<int, node *> &graph, node *curNode) {
  curNode->is_visited = 1;

  for (int connected : curNode->connected_node) {
    if (!graph[connected]->is_visited) {
      dfs(graph, graph[connected]);
    }
  }
}

int count(unordered_map<int, node *> &graph) {
  int connected_component = 0;

  for (const auto &pair : graph) {
    if (!pair.second->is_visited) {
      dfs(graph, pair.second);
      connected_component++;
    }
  }

  return connected_component;
}

int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, node *> graph = init(n, m);
  cout << count(graph);

  for (auto &pair : graph) delete pair.second;

  return 0;
}

//ถ้าให้แต่กูถูกแค่ 1 testcase กุไม่ทำต่อก้ด้าย ควย
