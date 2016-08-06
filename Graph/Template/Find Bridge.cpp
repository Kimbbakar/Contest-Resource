vector<int>lst;
vector<pair<int,int> > bridge;
int vist[],id=1;

int dfs(int nod,int p)
{
    vist[nod]=id;
    int mn=id++;
    bool ok=false;
    int l=0,z;


    for(int i=0;i<sz(aj_list[nod] );i++ )
    {
        int k=aj_list[nod][i];
        if(vist[k]==0)
        {
            l++;
            z=dfs(k,nod);
            mn=min(mn,z );
            if(z>vist[nod])
            {
                bridge.pb(make_pair(nod,k) );
            }
        }
        else if(k!=p)
            mn=min(mn,vist[k] );
    }

    return mn;
}
