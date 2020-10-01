#include <bits/stdc++.h>
using namespace std;
int n=5;
bool visited[5];
void bfs(vector<int> graph[],int src){
	queue<int> q;
	q.push(src);
	visited[src]=true;
	while(!q.empty()){
		src=q.front();
		cout<<src<<" ";
		q.pop();
		for(int i=0;i<graph[src].size();i++){
			if(!visited[graph[src][i]]){
				visited[graph[src][i]]=true;
				q.push(graph[src][i]);
			}
		}
	}
}
void bfsUtil(vector<int> graph[]){
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			bfs(graph,i);
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
	bfsUtil(graph);
	
	return 0;
}
