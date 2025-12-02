#include <bits/stdc++.h>
using namespace std;
 
const long long INF = (long long)1e15;
typedef pair<int, int> pii;
 
struct Node{
  int node;
  int capa;
  long long cost;
  Node(int _node = -1, int _capa = -1, long long _cost = -1LL) : node{_node}, capa{_capa}, cost{_cost} {}
};
 
struct MyComparator{
  bool operator()(const Node& a, const Node& b){
    return a.cost > b.cost;
  }
};
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n, m; 
  cin >> n >> m;
  vector<vector<pii>>adj(n+1);
  for(int i = 0; i < m; ++i){
    int start, end, weight;
    cin >> start >> end >> weight;
    adj[start].push_back(make_pair(end, weight));
  }
  
  vector<vector<long long>>dist(n+1, vector<long long>(2, INF));
  vector<vector<bool>>is_relaxed(n+1, vector<bool>(2));
  dist[1][0] = dist[1][1] = 0;
  priority_queue<Node, vector<Node>, MyComparator> pq;
  pq.push(Node(1, 1, 1));
  while(!pq.empty()){
    Node t = pq.top(); pq.pop();
    int cur_node = t.node, capa = t.capa;
    if(is_relaxed[cur_node][capa])
      continue;
    is_relaxed[cur_node][capa] = true;
    for(auto[child, weight] : adj[cur_node]){
      long long contri = dist[cur_node][capa] + weight;
      if(contri < dist[child][capa]){
        dist[child][capa] = contri;
        pq.push(Node(child, capa, contri));
      }
      if(capa == 1){
        long long contri = dist[cur_node][capa] + weight / 2;
        if(contri < dist[child][0]){
          dist[child][0] = contri;
          pq.push(Node(child, 0, contri));
        }
      }
    }
  }
  cout<<min(dist[n][1], dist[n][0]); 
}
