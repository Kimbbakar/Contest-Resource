// Problem Link: 

bool vis[33000];
bool mark[17][33000];
int dp[33000];
int done[33000]={0},cc=1;
vector<int>aj_list[17];
int u,v,n,m;
 
void dfs(int p,int mask)
{
    vis[mask]=1;
    mark[p][mask]=1;
    if(mask==(1<<n)-1) return;
 
    for(int i=0;i<sz(aj_list[p] );i++)
    {
        int k=aj_list[p][i];
        if(!mark[k][on(mask,k)])
        {
            dfs(k,on(mask,k));
        }
    }
 
}
 
 
int re(int mask)
{
    if(mask==0) return 0;
 
    if(done[mask]==cc) return dp[mask];
 
    done[mask]=cc;
    dp[mask]=inf;
 
    for(int i=mask;i!=0 ;i=(i-1)&mask)
    {
        if(vis[i])
        {
            dp[mask]=min(dp[mask],1+re(mask^i) );
        }
    }
 
    return dp[mask];
}
