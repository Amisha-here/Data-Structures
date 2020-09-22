#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s[4010],n,ar[1010];

void build(int id,int l,int r)
{
    if(r-l<2)
    {
        s[id]=ar[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2+1,l,mid);
    build(id*2+2,mid,r);
    s[id]=s[id*2+1]+s[id*2+2];
}

// prints sum of elements [x,y)
int sum(int x,int y,int id=0,int l=0,int r=n)
{
    if(x>=r || y<=l)
        return 0;
    if(x<=l && y>=r)
        return s[id];
    int mid=(l+r)/2;
    return sum(x,y,id*2+1,l,mid) + sum(x,y,id*2+2,mid,r);
}

void modify(int p,int x,int id = 0,int l = 0,int r = n)
{
    s[id] += x - ar[p];
    if(r - l < 2)
    {
        ar[p] = x;
        return ;
    }
    int mid = (l + r)/2;
    if(p < mid)
        modify(p, x, id*2+1, l, mid);
    else
        modify(p, x, id*2+2, mid, r);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    build(0,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cout<<"From: "<<i<<" to: "<<j<<" = "<<sum(i,j+1)<<endl;
        }
    }
    return 0;
}
