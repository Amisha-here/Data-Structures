
ll ft[N];

void update(int x, int delta){

      for(; x <= n; x += x&-x)
        ft[x] += delta;
}

ll query(int x){

     ll sum = 0;
     for(; x > 0; x -= x&-x)
        sum += ft[x];

     return sum;
}

ll pref(int x){

	ll ans = 0;
	while(idx > 0){

		ans += bit[idx];
		x -= x&-x;
	}
	return ans;
}