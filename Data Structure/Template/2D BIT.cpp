int tree[1005][1005];
bool ok[1005][1005];

void update(int x,int y)
{
    while(x<=1001)
    {
        int ys=y;

        while(ys<=1001)
        {
            tree[x][ys]++;

            ys=ys+(ys& -ys);//printf("%d %d %d\n",x,y,(ys & -ys) );pause
        }

        x=x+(x& -x);


    }
}

int qu(int x,int y)
{
    int res=0;
    while(x>=1)
    {
        int ys=y;

        while(ys>=1)
        {
            res+=tree[x][ys];

            ys=ys-(ys & -ys);

        }

        x=x-(x & -x);
    }

    return res;
}
