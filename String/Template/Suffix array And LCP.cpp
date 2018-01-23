
class nod
{
public:
    int F,S,P;

    bool operator <(const nod& a ) const
    {
        return (F==a.F)?(S<a.S ):(F<a.F);
    }
};

int pos[20][3*5004] ; // after every sort state of suffix
int sf_rank[3*5004]; // rank of i'th suffix
int suffix_array[3*5004]; // suffix position for i'th rank
int lcp[3*5004]; // lcp[i] = lcp(i,i+1)
nod taple[3*5004];
string s;
int n;

void build_suffix_array()
{
    for(int i=0;i<n;i++)
    {
        pos[0][i] =s[i]-'a';
    }

    for(int p=1,i=1;p<=n;p*=2,i++)
    {
        for(int j=0;j<n;j++)
        {
            taple[j].F=pos[i-1][j];
            taple[j].S=(j+p<n?pos[i-1][j+p]:-1 );
            taple[j].P=j;
        }

        sort(taple,taple+n);

        for(int j=0;j<n;j++)
        {
            pos[i][ taple[j].P ]=(j>0 && taple[j].F==taple[j-1].F && taple[j].S==taple[j-1].S ) ?pos[i][taple[j-1].P] :j;

            suffix_array[pos[i][ taple[j].P ]]=taple[j].P;
        }

    }

   for(int j=0;j<n;j++)
        sf_rank[suffix_array[j] ]=j ;

}

void build_lcp()
{
    for(int i=0,k=0;i<n;i++,(k>0)?k--:k )
    {
        if(sf_rank[i]==n-1 )
        {
            lcp[i] =0;
            continue;
        }

        int j=suffix_array[sf_rank[i]+1 ];

        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;

        lcp[i]=k;
    }
}
