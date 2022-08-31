//can work with neg edge and find neg edge cycle

#include<bits/stdc++.h>
#include<iostream>
#include<map>
#define  PI         acos(-1)
#define  ll         long long
#define  int        long long
#define  MAX       500005
#define  INF       1<<30     //10^9
#define  EPS       1e-9

#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

     
#define       MAX       500005
#define       INF       1<<30
#define       EPS       1e-9
typedef pair<int, int>              pii;
typedef pair<long long, long long>  pll;
typedef vector<int>                 vi;
typedef vector<pair<int,int>>       vii;
const int inf = 1e18+2; 



struct edge{
    int src, dest, cost;
    edge(int x,int y,int z){
        src=x, dest=y, cost=z;
    }
};

int n, e_nm;
vector<edge> ed;

int dist[100001],par[100001];    

void bellmanFord(int sc)    //O(V*E)
{
 
    int i,j;
    for(i=1;i<=n;i++){
       dist[i]= INF;
       par[i]= -1;
    }   
    
    dist[sc] = 0;
 
    // Relax all edges |V| - 1 times. 
    for (i = 1; i <= n-1; i++) {        //works for all edge every time
        for (j = 0; j<e_nm; j++) {
            int u = ed[j].src;
            int v = ed[j].dest;
            int wt = ed[j].cost;

            if (dist[u] != INF && dist[u]+wt < dist[v]){
                dist[v] = dist[u] + wt;
                par[v] = u;
            }
        }
    }
 
    for (int i = 0; i < e_nm; i++) {
        int u = ed[i].src;
        int v = ed[i].dest;
        int wt = ed[i].cost;
        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            printf("Graph contains negative weight cycle");
            return;         // If negative cycle is detected, simply return
        }
    }
  
    return;
}
  
void path(int n)  
{
     vector<int> path;
     if(par[n] == -1){
         cout<<"-1\n"; return;
     }
     path.push_back(n);
 
     int cur = n;
     while(par[cur] != -1){
         path.push_back(par[cur]);
         cur = par[cur];
     }
     reverse(path.begin(), path.end());
    
     for(auto it: path){
         cout<<it<<' ';
     }
}



signed main()
{
    //FastRead;
    int i,j,x,y,w;

    cin>>n>>e_nm;
    

    for(i=0;i<e_nm;i++){
        cin>>x>>y>>w;

        ed.push_back(edge(x, y, w)); //directed graph
    }

    bellmanFord(1);
    
    for(i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
    
    //path(n);
    

    return 0;
}

