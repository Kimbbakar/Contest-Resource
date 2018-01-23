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

int res[1000006];

void segmented_sieve(int a,int b)
{
    for(int i:prime)
    {
        if(i<=sqrt(b))
        {
          //  if(i==2) continue;

            ll st=(i>a)?i:(a/i)*i ;// what_is(st)

            if(st<=MAX && mark[st]==0)
                st+=i;

            while(st<a && st<b)
                st+=i;

             while(st<=b)
            {
                res[st-a]=1;
                st+=i ;
            }
        }
        else break;
    }
}