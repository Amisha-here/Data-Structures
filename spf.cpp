
ll spf[N]; 

void sieve() {

    spf[1] = 1; 
    for (int i = 2; i < N; i++) 
  		spf[i] = i; 
   
    for (int i = 4; i < N; i += 2) 
        spf[i] = 2; 
  
    for (int i = 3; i*i < N; i++) {

        if (spf[i] == i) 
        {  
            for (int j = i*i; j < N; j += i) 
  
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

vector<int> factors(int x) {

    vector<int> res; 
    while (x != 1) 
    { 
        res.pb(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 