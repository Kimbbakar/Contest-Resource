#define MAX 5004

vector<int>lst[MAX];
int id=1;
int visit[MAX];
int scc[MAX];
int bcc[MAX],bi=0;
stack<int>s;
int n; // number of nodes;

void clr(){
    reset(visit,0);
    for(int i=0;i<=n;i++)
        lst[i].clear();
    id = 1;
}

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

    if(scc[nod]==mn)
    {
        bi++;

        while(1)
        {
            int k=s.top();
            s.pop();
            visit[k]=2;

            bcc[k]=bi;
            if(k==nod)
                break;
        }

    }

    return mn;

}
