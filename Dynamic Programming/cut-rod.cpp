#include <bits/stdc++.h>

using namespace std;

int t[9][9];
int un_kp(int price[], int length[], 
                    int Max_len, int n)
{
    if (n == 0 || Max_len == 0) 
    {
        return 0;
    }
    if (length[n - 1] <= Max_len) 
    {
        t[n][Max_len]
            = max(price[n - 1]
                      + un_kp(price, length,
                           Max_len - length[n - 1], n),
                  un_kp(price, length, Max_len, n - 1));
    }
 
    else
    {
        t[n][Max_len]
            = un_kp(price, length, 
                              Max_len, n - 1);
    }
    return t[n][Max_len];
}
int main()
{
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;
 
    cout << "Maxmum obtained value  is "
         << un_kp(price, length, n, Max_len) << endl;
}