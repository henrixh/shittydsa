#include <bits/stdcpp.h>
using namespace std;
typedef int V;

struct Node {
  V dist;
  int prev;
};

struct Edge {
  int from, to;
  V w;
};

typedef vector< vector<Edge> > AdjacencyList;

/*
  Implementation of shortest path algorithm (Dijkstra) with function
  to query path for a single node.
*/

vector<Node> Dijkstra(const Adjacencylist& adj, int s) {
  // The nodes are ordered from 0...adj.size() - 1
  // Shortest path graph is constructed with s as source
  const auto size = adj.size();
  const V INF = numeric_limits<V>::max();
  vector<Node> n(size, Node{INF, -1});

  struct State {
    ValueT d;
    int idx;
  };

  struct Comparator {
    bool operator() (const State& lhs, const State& rhs) {
      return lhs.d > rhs.d;
    }
  }

  priority_queue<State, vector<State>, Comparator> pq;
  pq.push({0, s});

  vector<bool> visited(n.size());
  while (!pq.empty()) {
    const auto s_i = pq.top(); pq.pop();
    const auto node = s_i.idx;
    if (visited[node]) continue;

    visited[node] = true;
    for (const auto& e : adj[node]) {
      V next = n[e.from].dist + e.w;
      if (next < n[e.to].dist) {
        n[e.to].dist = next;
        pq.push({next, e.to});
        n[e.to].prev = e.from;
      }
    }
  }
}

vector<int> PathTo(const vector<Node>& n, int t) {
  // n should be result of Dijkstra and t is the target index

  // Construct reverse path then reverse the reverse path to get the
  // reverse reverse (correct) path
  vector<int> pos;
  pos.push_back(t);
  while (n[pos[pos.size() - 1]].prev != -1) {
    t = n[pos[pos.size() - 1]].prev;
    pos.push_back(t);
  }

  const auto Mid = (int) (pos.size() / 2);
  const auto End = pos.size() - 1;
  for (auto k = 0; k < Mid; ++k) {
    swap(pos[k], pos[End - k]);
  }

  return pos;
}
