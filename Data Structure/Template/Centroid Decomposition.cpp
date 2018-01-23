set<pair<int,int> > DFS(int nod,int par,int id){

    set<pair<int,int> > x1;

    mark[nod] = id; 
    child[nod]=1;

    for(int i:lst[nod]){

        if(i==par || mark[i]==-1) continue;

        set<pair<int,int> > x2 = DFS(i,nod,id);
        child[nod]+=child[i]; 

        if(sz(x1)<sz(x2))
            swap(x1,x2);

        for(auto j:x2)
            x1.insert(j);
    }

    x1.insert({child[nod],nod} );

    return x1;
}

void build(int id){

    bool ok = false;
    for(int i=1;i<=n;i++){
        if(mark[i]==-1 || mark[i]==id) continue;

        ok = true;
        set<pair<int,int>  > tmp = DFS(i,-1,id);

        int v = tmp.rbegin()->F;
        v = tmp.lower_bound({(v+1)/2,0} ) ->S;

        for(auto j:tmp)
            if(j.S!=v)
                preC[j.S]=v;
    
        mark[v] = -1;
    }

    if(ok)
        build(id+1);

}


int distance(int a,int b){
    if(level[a]>level[b])
        swap(a,b);
 
    int c = 0;

    for(int ln =  log2(n);ln>=0 and level[b]>level[a] ;ln--) {
        if(level[table[b][ln] ]>=level[a] ){
            c+=cost[b][ln];
            b=table[b][ln];
        }
 
    }
     

    if(a==b)
        return c;

    for(int ln =  log2(n);ln>=0    ;ln--) {

        if(table[a][ln]==table[b][ln]) continue;
        c+=cost[a][ln];
        c+=cost[b][ln];

        a = table[a][ln];
        b = table[b][ln]; 
        
    }


    c+=cost[a][0];
    c+=cost[b][0];

    return c;

}

int ans[100005];

void update(int nod,int red){
    if(!nod)
        return;

    ans[nod] = min(ans[nod],distance(nod,red) );

    update(preC[nod],red );
}

int qu(int nod,int nw){
    if(!nod)
        return inf;

    return min(ans[nod] + distance(nw,nod),qu(preC[nod],nw )  );
}
