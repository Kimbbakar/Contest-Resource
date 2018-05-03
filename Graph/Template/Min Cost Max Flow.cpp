#define MNODE 102 
#define MEDGE 20005 

ll cost[MEDGE],cap[MEDGE],flow[MEDGE],mark[MNODE];
int path[MNODE];
int _source,_sink;
int _node,_edge;
vector<pair<int,int> > edges;

inline void init(int n, int s,int d ) {
    _node   = n;
    _source = s;
    _sink   = d;
    _edge = 0;
    edges.clear();
    reset(cap,0);
    reset(flow,0);
    reset(cost,0);
}

/*
    u = from
    v = to
    f = flow 
    c = cost
*/

void addEdge(int u,int v,int f,int c){
    cost[_edge] = c;
    edges.pb({u,v} );
    cap[_edge] = f;
    flow[_edge] = 0;
    _edge++;

    cost[_edge] = - c;
    edges.pb({v,u} );
    cap[_edge] = 0; // directed . For unidirection cap[_edge] = f
    flow[_edge] = 0;
    _edge++;
}
 
bool bellmanFord()
{
    reset(path,-1);
    for(int i=0;i<=_node;i++)
        mark[i]=inf;
    mark[_source]=0; 
    bool ok=true;

    for(int _t=1;_t<=_node;_t++ ){
        ok=false;
 
        for(int i=0;i<_edge;i++){
            if(mark[edges[i].S]> cost[i] + mark[edges[i].F] && cap[i] ){
                mark[edges[i].S] = cost[i] + mark[edges[i].F];
                ok=true;
                path[edges[i].S]=i;
            }            
        }
    

  
        if(!ok) break;
    }
 
    return (mark[_sink]<(inf) );
}

pair<int,ll> mcmf(){
    ll ans = 0;
    int cnt = 0;
    while(bellmanFord() )
    {
        cnt ++;
        int y=_sink;
        while(path[y]!=-1){ 
            cap[path[y]]--;
            cap[path[y]^1]++;

            flow[path[y]]++;
            flow[path[y]^1]--;

            ans+=cost[ path[y] ];
            y=edges[ path[y] ].F ;
        }
 
    }    

    return {cnt,ans};
}
