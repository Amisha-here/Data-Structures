#define v vector
void topo(v<v<int>>& g, int n){
   v<bool>ind(n,0);
   queue<int> q;
   vector<int> ans;
   for(int i = 0;i<n;i++){
       for(auto j : g[i]){
           ind[j]++;
       }
   }
   for(int i = 0;i<n;i++){
       if(ind[i]==0) q.push(i);
   }
   while(!q.empty()){
       int t = q.front();
       q.pop();
       ans.push_back(t);
       for(auto i : g[t]){
           if(--ind[i]==0) q.push(i);
       }
   }
   if(ans.size()!=n) cout<<"THERE IS A CYCLE";
   else for(auto i : ans) cout<<i<<" ";   
}
