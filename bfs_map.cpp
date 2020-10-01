//DFS on MAP in C++
class DFS_Map {
           vector<vector<int> > E;
           int R, C;
public:
           DFS_Map(int r, int c) {
                      R = r; C = c;
                      E = vector<vector<int> >(R + 2, vector<int>(C + 2, 0));
           }
           void setRC(int r, int c, int w) {
                      E[r][c] = w;
           }
           int getRC(int r, int c) {
                      return E[r][c];
           }
           void dfs(int rr, int cc, vector<vector<bool> > &visited) {
                      int i, r, c, v;
                      visited[rr][cc] = true;
                      for (i = 0; i < 4; i++) {
                                 r = rr + dr[i]; c = cc + dc[i];
                                 if (E[r][c] && !visited[r][c]) {
                                            dfs(r, c, visited);
                                 }
                      }
           }
           void dfsAll() {
                      vector<vector<bool> > visited = vector<vector<bool> >(R + 2, vector<bool>(C + 2, 0));
                      int r, c;
                      for (r = 1; r <= R; r++) for (c = 1; c <= C; c++) if (!visited[r][c]) dfs(r, c, visited);
           }
};

