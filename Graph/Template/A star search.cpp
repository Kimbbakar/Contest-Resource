// not work for 15-puzzle

class data
{
 public:
    int P[3][3];
    int h,g,f,r,c;
    void in()
    {
        h=g=f=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&P[i][j]);
                if(P[i][j]==0)
                {
                    r=i,c=j;
                }
            }
        }
    }

    void print()const
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                printf("%d ",P[i][j] );

            printf("\n");
        }
    }

    int heuristic()const
    {
        int v=0;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(P[i][j]!=0)
                {
                    v+=abs(i-(P[i][j]-1)/3 ) + abs(j-(P[i][j]-1)%3 );
                }
            }
        }

        return v;
    }

    bool checker()const
    {
        bool v=true;

        if(P[2][2]!=0) return false;

        int c=1;

        for(int i=0;i<3 && v;i++)
        {
            for(int j=0;j<3 && v;j++)
            {
                if(P[i][j]!=c && (i!=2 || j!=2) ) v=false;

                c++;
            }
        }

        return v;
    }

    bool solve_able()const
    {
        int c=0;

        for(int i=0;i<9;i++)
        {
            int l=i/3;
            int r=i%3;
            for(int j=0;j<i && P[l ][r ] ;j++)
            {
                int l1=j/3;
                int r1=j%3;

                if(P[l1 ][r1 ] &&  P[l1 ][r1 ]>P[l ][r ])
                {
                    c++;
                }

            }
        }
        return (c%2)==0;
    }

    ll hash_value()const
    {
        ll v=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                v=v*10+P[i][j];
            }
        }

        return v;
    }

    bool operator <(const data& p) const
    {
        return f>p.f || (f==p.f && g>p.g);
    }

};

int x[]={-1,0,1,0};
int y[]={0,1,0,-1};


int solve(data& P)
{
    priority_queue<data>q;

    P.f=P.hash_value();

    q.push(P);

    data nw,sp;

    int ans;

    map<long long,int>mark;

    mark[P.hash_value() ]=true;
    while(!q.empty())
    {
        nw=q.top();
        q.pop();

        if(nw.checker())
        {
            ans=nw.g;
            break;
        }

        for(int i=0;i<4;i++)
        {
            sp=nw;

            if(sp.r+x[i]>=0 && sp.c+y[i]>=0 && sp.r+x[i]<3 && sp.c+y[i]<3 )
            {
                swap(sp.P[sp.r][sp.c ],sp.P[sp.r+x[i] ][sp.c+y[i] ] );
                sp.r+=x[i],sp.c+=y[i];

                sp.f=nw.g+sp.heuristic();
                sp.g=nw.g+1;

                if(mark[sp.hash_value()]==false)
                {
                    mark[sp.hash_value()]=true;
                    q.push(sp);
                }
            }
        }
    }
    return ans;
}
