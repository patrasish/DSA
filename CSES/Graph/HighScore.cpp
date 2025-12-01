#include <bits/stdc++.h>
using namespace std;
 
const long long INF = (long long)1e15 + 5;
struct Edge{
 
    int start;
    int end;
    int weight;
 
    Edge(int s = -1, int e = -1, int w = -1) : start{s}, end{e}, weight{w} {}
};
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n, m; cin >> n >> m;
 
    vector<vector<int>>adj(n+1);
    vector<Edge> edges(m);
    
    for(int i = 0; i < m; ++i){
        int start, end, weight; cin >> start >> end >> weight;
        adj[start].push_back(end);
        edges[i] = Edge(start, end, weight);
    }
 
    vector<bool>isReachable(n+1);
    queue<int>q;
 
    isReachable[1] = true;
    q.push(1);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int child : adj[node]){
            if(!isReachable[child]){
                isReachable[child] = true;
                q.push(child);
            }
        }
    }
 
    vector<long long>dist(n+1, -INF);
    dist[1] = 0;
 
    for(int k = 1; k < n; ++k){
        bool allRelaxed = true;
        for(Edge edge : edges){
            int start = edge.start, end = edge.end, weight = edge.weight;
            long long contri = dist[start] + weight;
            if(contri > dist[end]){
                dist[end] = contri;
                allRelaxed = false;
            }
        }
        if(allRelaxed)
            break;
    }
 
    vector<bool>isSpecial(n+1);
    for(Edge edge : edges){
        int start = edge.start, end = edge.end, weight = edge.weight;
        long long contri = dist[start] + weight;
        if(contri > dist[end]){
            dist[end] = contri;
            if(isReachable[start])
                isSpecial[start] = true;
        }
    }
 
    for(int node = 1; node <= n; ++node){
        if(isSpecial[node])
            q.push(node);
    }
 
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int child : adj[node]){
            if(!isSpecial[child]){
                isSpecial[child] = true;
                q.push(child);
            }
        }
    }
 
    cout<<((isSpecial[n] == true) ? -1 : dist[n])<<'\n';
    return 0;
}
