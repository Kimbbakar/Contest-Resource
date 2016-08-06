vector<int>lst[MAX];
int match[MAX],rmatch[MAX];
bool visit[MAX];

bool dfs (int v)
{
    for(int i=0;i<sz(lst[v]);i++)
    {
        int u=lst[v][i];

        if(!visit[u] )
        {
             visit[u]=true;
            if(rmatch[u]==-1 || dfs(rmatch[u] ) )
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
