#define INF 100000000
#define MAX 100005

// Taken from Tarango Khan .

// Runtime O( sqrt(V) *E ) . For more details, look at wiki page

int N, M, E, R, C;
// N = Maximum number of matching possible from left set.

vector< int > Graph[MAX];
int Left[MAX];
int Right[MAX];
int dist[MAX];
int lCnt = 0,rCnt = 0;
// lCnt = is max number of elements in left set.
// rCnt = is max number of elements in right set.

bool BFS() {
    queue< int > Q;
    for(int i = 1; i<=N; i++) {
        if(Left[i] == 0) {
            dist[i] = 0;
            Q.push(i);
        } else {
            dist[i] = INF;
        }
    }
    dist[0] = INF;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        if(u != 0) {
            int len = Graph[u].size();
            for(int i = 0; i<len; i++) {
                int v = Graph[u][i];
                if(dist[Right[v]] == INF) {
                    dist[Right[v]] = dist[u] + 1;
                    Q.push(Right[v]);
                }
            }
        }
    }
    return (dist[0] != INF);
}

bool DFS(int u) {
    if(u != 0) {
        int len = Graph[u].size();
        for(int i = 0; i<len; i++) {
            int v = Graph[u][i];
            if(dist[Right[v]] == dist[u]+1) {
                if(DFS(Right[v])) {
                    Right[v] = u;
                    Left[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0;
    mems(Left,0);
    mems(Right,0);
    N = lCnt;
    while(BFS()){
        for(int i = 1; i<=N; i++){
            if(Left[i] == 0 && DFS(i)){
                matching++;
            }
        }
    }
    return matching;
}
