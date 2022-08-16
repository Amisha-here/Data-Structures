#include<iostream>
#include<stdio.h>
using namespace std;
#include<unordered_map>
#include<vector>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
        // int maxfre=0;
        // int maxnum=0;
        vector<int> n1;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            // maxfre=max(maxfre,m[nums[i]]);
        }
        for(auto i :m)
        {
            if(i.second>nums.size()/3)
            {
                n1.push_back(i.first);
            }
        }
        return n1;
    }
};
int main()
{
   vector<int>num;
   num.push_back(1);
   num.push_back(2);
//    num.push_back(3);
//    num.push_back(3);
//    num.push_back(3);
   Solution s;
    vector<int> a=s.majorityElement(num);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    
    return 0;
}
