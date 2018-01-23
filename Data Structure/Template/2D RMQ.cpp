int rmq [12] [505] [505] ;

int grid[505][505];

int n,q;

inline void op1()
{
    for(int k=0;(1<<k) <=n;k++)
    {
        for(int i=0; i + (1<<k)-1 <n;i++)
        {
            for(int j=0; j+(1<<k)-1 <n;j++)
            {
                if(k==0)
                    rmq[k][i][j]=grid[i][j];
                else
                    rmq[k][i][j] = max ( max( rmq [ k-1 ] [ i ] [ j ] , rmq[ k-1 ] [ i ] [ j + (1<<(k-1) ) ] ) , max( rmq [ k-1 ] [ i + (1<<(k-1) )  ] [ j ] , rmq[ k-1 ] [ i + (1<<(k-1) ) ] [ j + (1<<(k-1) )  ] ) ) ;
            }
        }
    }
}
