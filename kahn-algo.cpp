#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001;

using namespace std;

void Addedge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}  
bool kahn_algorithm(vector<int> adj[], vector<int> indegree, int v)
{
    int count = 0;
    deque<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push_back(i);
        }
    }
    count = q.size();
    while(!q.empty())
    {
        int x = q.front();
        q.pop_front();
        for(int u: adj[x])
        {
            indegree[u]--;
            if(indegree[u] == 0)
            {
                q.push_back(u);
                count++;
            }
            
        }
    }
    
    return (count != v);
}

int main() 
{ 
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    vector<int> indegree(v, 0);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        indegree[y]++;
        Addedge(adj, x, y);
    }
    cout << (kahn_algorithm(adj, indegree, v) ? "Yes":"No");

    return 0; 
} 