vector<int>lst;
set<int> point;
int vist[],id=1;


int dfs(int nod)
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
            z=dfs(k);
            mn=min(mn,z );
            if(z>=vist[nod])
                ok=true;
        }
        else
            mn=min(mn,vist[k] );
    }

    if(nod==1) // For starting point
    {
        if(l>1 ) point.insert(nod);
    }
    else if(ok) point.insert(nod);
    return mn;
}
