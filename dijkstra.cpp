#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define heap priority_queue
#define vpii vector<pii>

void addEdge(int v, int w, int d, vpii vec[]) {
    vec[v].push_back(make_pair(d, w));
    vec[w].push_back(make_pair(d, v));
}

void dij(int s, vpii graph[], int v) {
    bool visited[v];
    int dist[v];
    heap < pii, vpii, greater<pii > > q; 
    for (int i = 0; i < v; i ++){
        visited[i] = false;
        dist[i] = - 1;
    }
    pii u;
    u.first = 0;
    u.second = s;
    q.push(u);    
    int vertice;
    while(!q.empty()) {
        u = q.top();            
        vertice = u.second;     
        q.pop();                
        if (dist[vertice] == -1) {
            dist[vertice] = u.first;
            for (int i = 0; i < graph[vertice].size(); i ++) { 
                if (dist[graph[vertice][i].second] == - 1) {
                    q.push(make_pair(graph[vertice][i].first + dist[vertice], graph[vertice][i].second));
                }
            }
        }
    }
}