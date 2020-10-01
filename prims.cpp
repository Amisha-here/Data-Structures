//Prims algorithm in C++
class Prim {
           int N;
           vector<vector<pair<int, int> > > E;
public:
           Prim(int n) {
                      N = n;
                      E = vector<vector<pair<int, int> > >(N + 1);
           }
           void insert(int u, int v, int w) {
                      E[u].push_back(make_pair(v, w));
           }
           vector<int> execute(ll &cost) {
                      int k;
                      vector<int> dist(N + 1, INF);
                      vector<bool> selected(N + 1, false);
                      dist[1] = 0; cost = 0;
                      priority_queue<pair<int, int> > pq;
                      pq.push(make_pair(0, 1));
                      for (k = 0; k < N; k++) {
                                 int w = -pq.top().first;
                                 int u = pq.top().second;
                                 pq.pop();
                                 if (selected[u] == true) {
                                            k--; continue;
                                 }
                                 cost += w; selected[u] = true;
                                 for (int i = 0; i < E[u].size(); i++) {
                                            int v = E[u][i].first;
                                            int w2 = E[u][i].second;
                                            if (selected[v] == true) continue;
                                            if (dist[v] > w2) {
                                                       dist[v] = w2;
                                                       pq.push(make_pair(-w2, v));
                                            }
                                 }
                      }
                      return dist;
           }
           void g() {
                      int i, n, e, s, u, v, w; ll cost; vector<int> ans;
                      scanf("%d%d", &n, &e);
                      Prim pm(n);
                      scanf("%d", &s);
                      for (i = 0; i < e; i++) {
                                 scanf("%d%d%d", &u, &v, &w);
                                 pm.insert(u, v, w);
                      }
                      ans = pm.execute(cost);
                      printf("%d", cost);
           }
};

