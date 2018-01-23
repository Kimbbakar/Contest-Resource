void build()
{
    for(int i=1;i<=16;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(table[j][i-1]!=-1 )
            {
               table[j][i]=table[table[j][i-1] ][i-1];
            }
        }
    }
}

void qu(int a,int b)
{
    if(dep[a]<dep[b] )
        swap(a,b);
    int lg;
    for(lg = 1; (1 << lg) <= dep[a]; lg++); lg--;
    for(int i=lg;i>=0;i--)
    {
        if(dep[a]-(1<<i)>=dep[b])
        {
            a=table[a][i];
        }
    }
    if(a==b) return;

    int k;

    for(int i=lg;i>=0;i--)
    {
        if(table[a][i]!=-1 && table[a][i]!=table[b] [i] )
        {
            a=table[a][i];
            b=table[b][i];
        }
    }
}
