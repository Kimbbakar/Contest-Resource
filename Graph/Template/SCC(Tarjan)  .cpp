 vector<int>aj_list[100];
 int id=1;
 int visit[100];
 int scc[100];
 int bcc[100],bi=0;
 stack<int>s;

 int tarjan(int nod,int p)
{
    visit[nod]=1;
    scc[nod]=id;

    s.push(nod);

    int mn=id++;

    for(int i=0;i<(aj_list[nod].size() );i++ )
    {
        int k=aj_list[nod][i];


        if(!visit[k])
        {
            mn=min(mn,tarjan(k,nod) );
        }
        else if(k!=p && visit[k]==1)
        {
            mn=min(mn,scc[k] );
        }

    }

    visit[nod]=2;
    if(scc[nod]==mn)
    {
        bi++;

        while(1)
        {
            int k=s.top();
            s.pop();

            bcc[k]=bi;
            if(k==nod)
                break;
        }

    }

    return mn;

}
