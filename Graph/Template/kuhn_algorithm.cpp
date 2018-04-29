#define MAX 1004

// Run Time O(N*E)

vector<int>lst[MAX];
int match[MAX],rmatch[MAX];
bool visit[MAX];

bool dfs (int v)
{
    for(int i=0;i<sz(lst[v]);i++)
    {
        int u=lst[v][i];
  
        if(rmatch[u]==-1   )
        {
            rmatch[u]=v;
            match[v]=u;
            return true;
        } 
    }

    for(int i=0;i<sz(lst[v]);i++)
    {
        int u=lst[v][i];
 
        if(!visit[u] )
        {
            visit[u]=true;
            if(dfs(rmatch[u] ) )
            {
                rmatch[u]=v;
                match[v]=u;
                return true;
            }
        }
    }
 
    return false;
}

int bpm(int n)
{
    int cnt=0;
    reset(rmatch,-1);
    for(int i=1;i<=n;i++)
    {
        reset(visit,false);
        if(dfs(i)  )
        {
            cnt++;
        }

    }

    return cnt;
}
