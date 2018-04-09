#define MAX 2000005

class PersistentSegTree{
public:
    int left,right;
    int v;
};

PersistentSegTree tree[4*MAX];
int StartNode[100004];
int u,v,s,id;

//  [l,r] = range cover by tree
//  [u,v] = range you are looking for  

void update(int &node,int l,int r){

    if(v<l or r<u) return;

    if(!node)
        node = ++id;

    if(l==r){
        tree[node].v = max(tree[node].v,s);
        return;
    }

    int mid  = (l+r)>>1; 

    update(tree[node].left ,l,mid);
    update(tree[node].right,mid+1,r);

    tree[node].v = max( tree[tree[node].left].v,tree[tree[node].right].v );
}


void qu(int &node,int l,int r){

    if(v<l or r<u) return;

    if(u<=l and r<=v){
        s= max(tree[node].v,s);
        return;
    }

    int mid  = (l+r)>>1; 

    qu(tree[node].left ,l,mid);
    qu(tree[node].right,mid+1,r);
}