#include <bits/stdc++.h>
using namespace std;
int n=5;
bool visited[5];

void dfs(vector<int> graph[],int s){
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<graph[s].size();i++){
    	if(!visited[graph[s][i]]){
    		dfs(graph,graph[s][i]);
		}
	}
}

void dfsUtil(vector<int> graph[]){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(graph,i);
        }
    }
}

int main() {
	vector<int> graph[n];
	graph[0].push_back(1);
	graph[0].push_back(4);
	graph[1].push_back(0);
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(1);
	graph[3].push_back(2);
	graph[3].push_back(4);
	graph[4].push_back(0);
	graph[4].push_back(1);
	graph[4].push_back(3);
	dfsUtil(graph);
	
	return 0;
}
