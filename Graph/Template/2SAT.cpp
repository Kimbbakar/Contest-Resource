#define MAX 2005

int nod(int x)
{
    if(x<0)
    {
        return abs(x)+1000;
    }
    return x;
}

vector<int>lst[MAX];
vector<int>lst1[MAX];
int n,m,k;
int u,v;

int visit[MAX];
int mark[MAX];
int col[MAX];
int taken[MAX];
stack<int>st;
int id,cl;

int scc(int p)
{
    visit[p]=1;
    mark[p]=id;
    int mn=id++;
    st.push(p);

    for(int j=0;j<sz(lst[p] );j++)
    {
        int i=lst[p][j];
        if(visit[i]==0)
        {
            mn=min(mn,scc(i) );
        }
        else if(visit[i]==1)
        {
            mn=min(mn,mark[i] );
        }
    }

    visit[p]=2;

    if(mn==mark[p])
    {
        while(st.top()!=p)
        {
            col[st.top()]=cl;
            lst1[cl].pb(st.top());
            st.pop();
        }
        lst1[cl].pb(st.top());
        col[st.top()]=cl;
        st.pop();

        cl++;

    }

    return mark[p]=mn;
}

bool found;
vector<int>res;

bool solve(int x)
{
    id=1;
    cl=1;

    for(int i=0;i<MAX;i++)
    {
        lst1[i].clear();
        lst2[i]=lst[i] ;
        mark[i]=0;
        visit[i]=0;
        col[i]=0;
    }

    bool ok=false;

    for(int i=1;i<=m;i++)
    {
        if(visit[i]==0)
            scc(i);
    }

    for(int i=1;i<=m && !ok;i++)
    {
        if(col[i]==col[nod(-i) ] )
        {
            ok=true;
        }
    }

    return !ok;
}

void print()
{
    for(int i=1;i<cl ;i++)
    {
        for(int j=0;j<sz(lst1[i] );j++)
        {
            int k=lst1[i][j];

            if(taken[k]) continue;

            if(k<=1000 )
            {
                taken[k]=1;
                taken[k+1000]=1;
                res.pb(k);
                cnt++;
            }
            else
            {
                taken[k]=1;
                taken[k-1000]=1;
            }
        }
    }
}
