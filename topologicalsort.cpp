//Topological Sort  
vector<int> topologicalSort() {
                      vector<int> order;
                      queue<int> Q;
                      for (int i = 1; i <= N; i++) if (!IN[i]) Q.push(i);
                      while (!Q.empty()) {
                                 int u = Q.front();
                                 Q.pop(); order.push_back(u);
                                 for (int i = 0; i < E[u].size(); i++) {
                                            int v = E[u][i].first;
                                            if (IN[v]>0) {
                                                       IN[v]--;
                                                       if (!IN[v]) Q.push(v);
                                            }
                                 }
                      }
                      return order;
           }
           vector<int> topologicalSortPQ() {
                      vector<int> order;
                      priority_queue<int> pq;
                      for (int i = 1; i <= N; i++) if (!IN[i]) pq.push(-i);
                      while (!pq.empty()) {
                                 int u = -pq.top();
                                 pq.pop(); order.push_back(-u);
                                 for (int i = 0; i < E[u].size(); i++) {
                                            int v = E[u][i].first;
                                            if (IN[v]>0) {
                                                       IN[v]--;
                                                       if (!IN[v]) pq.push(-v);
                                            }
                                 }
                      }
                      return order;
           }
           int f() {
                      int v, u, i; vector<int> IN2;
                      for (u = 1; u <= N; u++) {
                                 for (i = 0; i<E[u].size(); i++) {
                                            v = E[u][i].first;
                                            if (IN[v] == 1) {
                                                       IN2 = IN;
                                                       IN[v]--;
                                                       topologicalSort();
                                                       if (!is_cycle()) return 1;
                                                       IN = IN2;
                                            }
                                 }
                      }
                      return 0;
           }
           void g() {
                      int i, j, N, m, a, b, c, a2, b2, c2, lo, hi, mid, tmp, start, end;
                      vector <tuple<int, int, int> > X; vector<ll> y;
                      scanf("%d%d", &N, &m);
                      BFS_Graph bg(N); X.reserve(m);
                      for (i = 0; i < m; i++) {
                                 scanf("%d%d%d", &a, &b, &c);
                                 if (a > b) tmp = a, a = b, b = tmp;
                                 X.push_back(make_tuple(a, b, -c));
                      }
                      scanf("%d%d", &start, &end);
                      sort(X.begin(), X.end());
                      bg.insert_fb(get<0>(X[0]), get<1>(X[0]), -get<2>(X[0]));
                      for (i = 1; i < m; i++) {
                                 a = get<0>(X[i - 1]); b = get<1>(X[i - 1]); c = get<2>(X[i - 1]);
                                 a2 = get<0>(X[i]); b2 = get<1>(X[i]); c2 = get<2>(X[i]);
                                 if (a == a2 && b == b2) continue;
                                 bg.insert_fb(a2, b2, -c2);
                      }
                      lo = 1; hi = INF;
                      while (lo < hi) {
                                 mid = (lo + hi + 1) / 2;
                                 y = bg.bfs(start, end, mid);
                                 if (y[end] < INF_LONG) {
                                            lo = mid;
                                 }
                                 else {
                                            hi = mid - 1;
                                 }
                      }
                      printf("%d", lo);
           }
};
