
ll p[N], size[N];
 
void init( ) {
    rep(i, 1, maxn){
        p[i] = i;
        size[i] = i;
    }
}
 
int root(int v) {
    if (v == p[v])
        return v;
    return p[v] = root(p[v]);
}
 
void merge(int a, int b) {
    a = root(a);
    b = root(b);
    if (a != b){
        if(size[a] < size[b])
            swap(a, b);
        p[b] = a;
        size[a] = max(size[a], size[b]);
    }
}