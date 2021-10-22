#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> sol;
    if (nums.size() < 3)
    {
        return sol;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        cout << "A\n";
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            cout << "B" << endl;
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                cout << "C\n";
                vector<int> t = {nums[i], nums[l], nums[r]};

                cout << "D\n";
                sol.push_back(t);
                l++;
            }
            else if (sum > 0)
            {
                cout << "E\n";
                r--;
            }
            else
            {
                cout << "F\n";
                l++;
            }
        }
    }
    sol.erase(unique(sol.begin(), sol.end()), sol.end());
    return sol;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> sol = threeSum(nums);
    for (vector<int> i : sol)
    {
        for (int j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
    cout << "hello there";
    return 0;
}