/*

author : Tandav
date   : 22Nov, 2025
prob   : Codeforces Div4(898), problem H
https://codeforces.com/problemset/problem/1873/H

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> get_dist(int start, int n, vector<vector<int>>& adj){
    vector<int>dist(n+1, -1);
    dist[start] = 0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int cur_node = q.front(); q.pop();
        for(int neighbor : adj[cur_node]){
            if(dist[neighbor] == -1){
                dist[neighbor] = 1 + dist[cur_node];
                q.push(neighbor);
            }
        }
    }
    return dist;
}
void solve(){
    int n, a, b; cin >> n >> a >> b;

    vector<vector<int>>adj(n+1);
    vector<int>degree(n+1);

    for(int i = 1; i <= n; ++i){
        int city1, city2; cin >> city1 >> city2;
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
        ++degree[city1]; ++degree[city2];
    }

    vector<bool>is_in_cycle(n+1, true);
    queue<int>q;
    for(int city = 1; city <= n; ++city){
        if(degree[city] == 1){
            is_in_cycle[city] = false;
            q.push(city);
        }
    }
    while(!q.empty()){
        int cur_city = q.front(); q.pop();
        for(int neighbor : adj[cur_city]){
            --degree[neighbor];
            if(degree[neighbor] == 1){
                is_in_cycle[neighbor] = false;
                q.push(neighbor);
            }
        }
    }
    
    vector<int>dist_from_a = get_dist(a, n, adj);
    vector<int>dist_from_b = get_dist(b, n, adj);
    for(int city = 1; city <= n; ++city){
        if((is_in_cycle[city] == true) && (dist_from_b[city] < dist_from_a[city])){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}