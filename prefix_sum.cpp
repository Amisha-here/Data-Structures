//C++ program for prefix sum
class PSum {
           PSum() {

           }
           vector<int> makeSum(const vector<int> &a, int n) {
                      vector<int> ret(a.size());
                      ret[0] = a[0];
                      for (int i = 1; i < a.size(); ++i)
                                 ret[i] = ret[i - 1] + a[i];
                      return ret;
           }
           vector<vector<int> > makeSum(const vector<vector<int> > &a, int n, int m) {
                      vector<vector<int> > ret(n, vector<int>(m));
                      int i, j;
                      for (i = 0; i < n; i++) ret[i][0] = a[i][0];
                      for (i = 0; i < n; i++) {
                                 for (j = 1; j < m; j++) {
                                            ret[i][j] = ret[i][j - 1] + a[i][j];
                                 }
                      }
           }
           int getSum(const vector<int>& psum, int a, int b) {
                      if (a == 0) return psum[b];
                      return psum[b] - psum[a - 1];
           }
           int getSum(const vector<vector<int> >&psum, int r1, int c1, int r2, int c2) {
                      int ret = psum[r2][c2];
                      if (r1 > 0) ret -= psum[r1 - 1][c2];
                      if (c1 > 0) ret -= psum[r2][c1 - 1];
                      if (r1 > 0 && c1 > 0) ret += psum[r1 - 1][c1 - 1];
                      return ret;
           }
};
