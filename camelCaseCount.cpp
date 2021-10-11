// Link to the question on hackerrank: https://www.hackerrank.com/challenges/camelcase/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {

    int count = 0;
    for(int i = 0 ; i < s.size(); i++)
    {
        if(s[i] <= 'Z')
        {
            count++;
        }
    }
    return count+1;

}

int main()
{
    
    string s;
    getline(cin, s);

    int result = camelcase(s);

    cout << result << "\n";

    return 0;
}
