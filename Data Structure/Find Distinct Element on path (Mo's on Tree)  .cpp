// Distinct Element on the path u to v 
// Flat the Tree with DFS

int n,q;
int val[100005];
int new_array[200005],cur=1;
int st[100005];
int ed[100005];
int table[20][100005];
int level[100005];
vector<int>lst[100005];
int cc[100005];

void dfs(int nod,int par){

    table[0][nod] = par;
    new_array[cur] = nod;
    st[nod] = cur++;
    level[nod]=level[par]+1;

    for(int i:lst[nod]){
        if(par==i)
            continue;

        dfs(i,nod);
    }

    new_array[cur] = nod ;
    ed[nod]=cur++;
}

void sp_table(){

    for(int i=1;i<=log2(n);i++){
        for(int j=1;j<=n;j++){
            if(table[i-1][j])
                table[i][j]=table[i-1][table[i-1][j] ];
        }
    }
}

int lcp(int a,int b){
 
	if(level[a]<level[b])
		swap(a,b);


	int lg = log2(n);

	while(lg>=0 ){

		if(level[a]-(1<<lg)>=level[b])
			a = table[lg][a];

		lg --;
	}


	if(a==b)
		return a;

	lg = log2(n);
	while(lg>=0){
		if(table[lg][a]!=table[lg][b]){
			a = table[lg][a];
			b = table[lg][b];
		}
		lg--;
	} 
	return table[0][a];
}

int res[100005];

class nod{
public:
	int l,r;
	int idx;
	int lcp; 
};

nod qu[100005];
int dv;

bool cmp1(nod a,nod b){
	if(a.l/dv!=b.l/dv)
		return (a.l/dv<b.l/dv);

	return (a.r<b.r);
}

int cnt[100005];
//map<int,int>cnt;

inline void chk(int idx,int &res){

	assert(new_array[idx]<=n );
	assert(idx<=2*n );

	if(cc[new_array[idx]] and --cnt[ val[ new_array[idx] ] ]==0 )
		res--;
	else if( (!cc[new_array[idx]]) and  cnt[ val[ new_array[idx] ] ]++==0)
		res++;

	//pf("%d || %d %d %d \n",val[ new_array[idx] ],res,cc[new_array[idx]],cnt[ val[ new_array[idx] ] ]);

	cc[new_array[idx]]^=1;
}

int cp[100005];

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif
 
    in(n),in(q);

    for(int i=1;i<=n;i++){
        in(val[i]);    	
        cp[i-1]=val[i];
    }

    sort(cp,cp+n);

	for(int i=1;i<=n;i++){
		val[i] = lower_bound(cp,cp+n,val[i] )-cp;
	}


    int u,v;

    for(int i=1;i<n;i++){
        in(u),in(v);

        lst[u].pb(v);
        lst[v].pb(u);
    }

    dfs(1,0);
    sp_table();

    for(int i=0;i<q;i++){
    	in(u),in(v);

    	if(st[u]>st[v])
    		swap(u,v);

    	int p = lcp(u,v);  

    	assert(p<=n);

    	qu[i].idx=i;

    	if(u!=p and v!=p){
	    	qu[i].l=ed[u];
	    	qu[i].r=st[v];    		
    		qu[i].lcp=p;
    	}
    	else{
	    	qu[i].l=st[u];
	    	qu[i].r=st[v];    		
    		qu[i].lcp=-1;    		
    	} 
    }

    dv = 1000; 
    sort(qu,qu+q,cmp1);

    int l=1,r=1;  
    cnt[ val[new_array[l]] ]++;
    cc[ new_array[l]]++;
    int tmp =1;  

    for(int i=0;i<q;i++){

  	while(l<qu[i].l) chk(l++,tmp) ;   
    	while(qu[i].l<l) chk(--l,tmp);
    	while(r<qu[i].r) chk(++r,tmp) ;  
    	while(qu[i].r<r) chk(r--,tmp);

    	res[qu[i].idx]=tmp;

     	if(qu[i].lcp!=-1 and cnt[val[qu[i].lcp] ]==0 )
			res[qu[i].idx]++;     		

    } 
    for(int i=0;i<q;i++)
    	pf("%d\n",res[i]);


    return 0;
}

