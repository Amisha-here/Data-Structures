

int bfs(int s) {
    queue<int> q;
    vector<bool> visited(n);
    int visCount = 0;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
    	
        int c = q.pop();
        for (auto v: graph[c]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
                
        visCount += 1;
    }

    return visCount;
}