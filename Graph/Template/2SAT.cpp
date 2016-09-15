#define MAX 16006


vector<int>lst[MAX];
vector<int>lst1[MAX];
int n,m,k;
int u,v;
int s[MAX];

int visit[MAX];
int id;

int dfs(int p)
{
    if(visit[p^1] ) return 0;
    if(visit[p] ) return 1;

    visit[p]=1;
    s[id++]=p;

    for(int j=0;j<sz(lst[p] );j++)
    {
        int i=lst[p][j];

        if(!dfs(i)) return 0;

    }

    return 1;
}


vector<int>res;

bool solve()
{
    bool ok=false;

    for(int i=0;i<2*m && !ok;i++)
    {
        id=0;
        if(visit[i]==0)
        {
            if(!dfs(i))
            {
                for(int j=0;j<id;j++)
                {
                    visit[s[j] ]=visit[s[j]^1 ]=0;
                }
                id=0;

                if(!dfs(i^1) )
                    ok=true;
            }
        }

    }

    return !ok;
}

void print()
{
    for(int i=0;i<2*m ;i++)
    {
        if(visit[i] )
            res.pb(i);
    }
}
