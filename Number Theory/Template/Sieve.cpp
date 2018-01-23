#define MAX 1000000
vector<int>prime;
int mark[MAX+5];

void sieve()
{
    prime.pb(2);

    for(int i=4;i<=MAX;i+=2)
        mark[i]=1;

    mark[1]=1;

    for(int i=3;i<=MAX;i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);

            for(ll j=(ll)i*i;j<=MAX;j+=(2*i))
                mark[j]=1;
        }
    }
} 