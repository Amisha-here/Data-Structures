//Floyd Warshall algorithm class
class Floyd {
           int N;
           vector<vector<int> > E;
public:
           Floyd(int n) {
                      N = n;
                      E = vector<vector<int> >(N + 1, vector<int>(N + 1, INF));
           }
           void setRC(int r, int c, int w) {
                      E[r][c] = w;
           }
           int getRC(int r, int c) {
                      return E[r][c];
           }
           void execute() {
                      int i, j, k;
                      for (i = 1; i <= N; ++i) E[i][i] = 0;
                      for (k = 1; k <= N; ++k) for (i = 1; i <= N; ++i) for (j = 1; j <= N; ++j)
                                 E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
           }
};

