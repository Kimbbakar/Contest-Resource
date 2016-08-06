inline void bellman()
{
    cost[1]=0;

    for(int i=1;i<nd;i++)
    {
        for(int j=0;j<sz(path);j++)
        {
            if(cost[path[j].u]+path[j].w <cost[path[j].v ] && cost[path[j].u]<100000000)
            {
                cost[path[j].v]=cost[path[j].u]+path[j].w;
            }
        }
    }
}

inline void check_neg_cycl()
{
    for(int i=1;i<nd;i++)
    {
        for(int j=0;j<sz(path);j++)
        {
            if(cost[path[j].u]+path[j].w <cost[path[j].v ] && cost[path[j].u]<100000000)
            {
                cost[path[j].v]=cost[path[j].u]+path[j].w;
                neg[path[j].v]=1;
            }
	}
    }
}