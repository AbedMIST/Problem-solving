//Disjoint set union to find cycle
//representing set as tree

#include<bits/stdc++.h>
#include<iostream>
#include<map>
#define PI         acos(-1)
#define ll         long long
#define int        long long

#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;


#define       MAX       500005
#define       INF       1<<30
#define       EPS       1e-9
typedef pair<int, int>              pii;
typedef pair<long long, long long>  pll;
typedef vector<int>                 vi;
typedef vector<pair<int,int>>       vii;
const ll inf = 1000000000000ll;




struct node{
    int vx;
    int wt;
    node(int v,int w){
        vx=v;
        wt=w;
    }
    bool operator < (const node& p) const {   return wt >p.wt;}
};

int n,e;

int dist[100001];    //biggest memory
int par[100001];
void Dijkstra(int src,vector< pair<int,int> >graph[]){  //O(E*log(V))
    bool visit[100001];
    for(int i=1;i<=n;i++){
        dist[i]=inf;
        visit[i]=false;
    }

    priority_queue <node> pq;
    pq.push(node(src,0));
    dist[src]=0;
    par[src]=src;       //root
    while(!pq.empty()){
        node tp=pq.top();
        pq.pop();
        int W=tp.wt;
        int V=tp.vx;
        if(visit[V]==true)  continue;
        visit[V]=true;              //explored

        for(int i=0;i<graph[V].size();i++){
            pair<int,int> pr = graph[V][i];
            int u=pr.first;        //child node
            int w=pr.second;
            if(dist[u]>W+w){    //update possible
                dist[u]= w+W;
                par[u]= V;
                pq.push(node(u,w+W));
            }
        }
    }
}

void printPath(int x)
{
    if(par[x]==x){
        cout<<x<<" ";
        return;
    }

    printPath(par[x]);      //no return in void type
    cout<<x<<" ";
}

signed main()
{
    FastRead;
    int i,j,x,y,w;
    vector< pair<int,int> > gra[100001];

    cin>>n>>e;
    for(i=0;i<e;i++){
        cin>>x>>y>>w;

        gra[x].push_back({y,w});
        gra[y].push_back({x,w});
    }

    Dijkstra(1,gra);

    // for(i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    if(dist[n] != inf)    printPath(n);
    else    cout<<-1;                   //path not found
    

    return 0;
}

