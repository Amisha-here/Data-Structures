//Palinmdrome Number
class Palindrome {
public:
           Palindrome() {

           }
           int isPalindrome(ll xx) {
                      ll x; int i, n; vector <int> v;
                      for (x = xx; x > 0; x /= 10) {
                                 v.push_back(x % 10);
                      }
                      n = v.size();
                      for (i = 0; i < n / 2; i++) {
                                 if (v[i] != v[n - i - 1]) return 0;
                      }
                      return 1;
           }
};

