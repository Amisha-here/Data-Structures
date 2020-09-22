///==================================================///
///
///  Ir0nic_  ///
///  MEHUL BHUTALIA  ///
/// Indian Institute Of Information Technology and Management,Gwalior.  ///
///
///==================================================///
	#include <bits/stdc++.h>

///--------------------------------------------------------------------------------
	#define     T()                             ll t;   cin >> t;         while(t--)
		#define         ll                  long long
		#define         vi                                  vector<ll>
		#define     pii                 pair<ll,ll>
		#define     piii                 pair<ll,pii >
		#define         vpair                           vector< pii >
		#define         fast                            ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
		#define     repp(i,a,n)         for(ll i = a; i < n; ++i)
		#define     rep(i,n)            for(ll i = 0; i < n; ++i)
		#define         p_b                                     push_back
		#define         p_f                             push_front
		#define         pop_b                           pop_back()
		#define         pop_f                           pop_front()
		#define         m_p                             make_pair
		#define         sumv(v)                         accumulate(v.begin(),v.end(),0);
		#define         sortv(v)                        sort(v.begin(),v.end())
		#define         sort_dec(v)             sort(v.begin(),v.end(),greater<ll>() )
		#define         l_b(v,l)                    lower_bound (v.begin(), v.end(), l)
		#define         u_b(v,l)                    upper_bound (v.begin(), v.end(), l)
		#define         pq                                      priority_queue
		#define         ff                                      first
		#define         ss                                      second
		#define     len                 length()
		#define     all(v)              v.begin(),v.end()
	#define     mset(a,b)           memset(a,b,sizeof(a));

///==========INPUT=============///
		#define     sc(a)           scanf("%lld",&a);
	#define     sc2(a,b)        scanf("%lld%lld",&a,&b);
	#define     sc3(a,b,c)      scanf("%lld%lld%lld",&a,&b,&c);
	#define     sc4(a,b,c,d)    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);

///==========PRINTING=============///
	#define     prarr(arr)      rep(i,sizeof(arr) / sizeof(ll)) cout << arr[i] << " "; nl
	#define     prvec(v)        rep(i,v.size()) cout << v[i] << " "; nl
	#define     pr(x)           cout << x << "\n";
	#define     pr2(x, y)       cout << x << " " << y << "\n";
	#define     pr3(x, y, z)    cout << x << " " << y << " " << z << "\n";

///==========DEBUGGING=============///
	#define     debug(a)                        cout << "*" << a << endl;
	#define     debug2(a,b)             cout << "$" << a << " " << b << endl;
	#define     debug3(a,b,c)           cout << "$" << a << " " << b << " " << c << endl;
		#define         bug                             cout << "#" << endl;
	#define     nl                                      cout << '\n';
	#define     endl                '\n'

///==========CONSTANTS=============///
	#define     max6     1000005
	#define     max5     100004
	#define     max4     10003
	#define     mod      1000000007
	#define     inf      1e9
ll powermod(ll _a,ll _b,ll _m)      {
	ll _r = 1; while(_b) {if(_b % 2==1) _r = (_r * _a) % _m; _b /= 2; _a = (_a * _a) % _m;} return _r;
}

using namespace std;
//----------------------------------------------------------------
  #define left 2 * i + 1
		#define right 2 * i + 2
		#define midd (start + end) / 2
//-------------------------------------------------------------
piii tree[2000005];
ll arr[200005];
void make(ll i,ll start,ll end)
{
	if(start==end)
		tree[i] = m_p(arr[start],m_p(start,1));
	else
	{
		ll mid = midd;
		make(left,start,mid);
		make(right,mid + 1,end);
		if(tree[left].ff==tree[right].ff)
		{
			tree[i] = tree[left];
			tree[i].ss.ss = tree[left].ss.ss + tree[right].ss.ss;
		}
		else if(tree[left].ff>tree[right].ff)
			tree[i] = tree[left];
		else
			tree[i] = tree[right];
	}
}
piii query(ll i,ll start,ll end,ll l,ll r)
{
	if(start>r||end<l)
		return m_p(0,m_p(0,0));
	else if(l<=start&&end<=r)
		return tree[i];
	ll mid = midd;
	piii a = query(left,start,mid,l,r);
	piii b = query(right,mid + 1,end,l,r);
	if(a.ff==b.ff)
	{
		piii c = a;
		c.ss.ss += b.ss.ss;
		return c;
	}
	else if(a.ff>b.ff)
		return a;
	else
		return b;
}
void update(ll i, ll st, ll en, ll index,ll val)
{
	if (st == index && en == index) {
		tree[i].ff = val;
		tree[i].ss.ss = 1;
		arr[st] = val;
		return;
	}
	int mid = (st + en) / 2;
	if(index >= st && index <= mid) {
		update(left, st, mid, index,val);
	} else {
		update(right, mid + 1, en, index,val);
	}
	if(tree[left].ff==tree[right].ff)
	{
		tree[i] = tree[left];
		tree[i].ss.ss = tree[left].ss.ss + tree[right].ss.ss;
	}
	else if(tree[left].ff>tree[right].ff)
		tree[i] = tree[left];
	else
		tree[i] = tree[right];
}
int main()
{
	ll n;
	sc(n)
	ll brr[n];
	rep(i,n)
	sc(arr[i])
	rep(i,n)
	sc(brr[i])
	make(0,0,n - 1);
	rep(i,n)
	{
		ll l = max(i - brr[i],(ll)0);
		ll r = min(i + brr[i],n - 1);
		piii p = query(0,0,n - 1,l,r);
		if(p.ss.ss==1)
		{ll g = (p.ff - arr[i]) / 3;
		 update(0,0,n - 1,i,g + arr[i]);
		 update(0,0,n - 1,p.ss.ff,arr[p.ss.ff] - g);}
	}
	rep(i,n)
	cout << arr[i] << " ";
}
/*
   5
   1 3 16 16 16
   3 3 3 3 3
 */
