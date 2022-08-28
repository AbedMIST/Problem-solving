#include<bits/stdc++.h>
#include<iostream>
#include<map>
#define PI         acos(-1)
#define ll         long long
#define MAX        100005
#define mod        1000000007  
#define pb         push_back
#define MP(x, y)   make_pair(x, y)
#define ff         first
#define ss         second
#define rep(i,n)   for(int i=0;i++<n;)
#define sci(a)     scanf("%d",&a)
#define scl(a)     scanf("%lld",&a)
#define b_s(a,b)   binary_search(a.begin(),a.end(),b)
#define l_b(a,b)   lower_bound(a.begin(),a.end(),b)
#define u_b(a,b)   upper_bound(a.begin(),a.end(),b)
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef pair<int, int>              pii;
typedef pair<long long, long long>  pll;
typedef vector<int>                 vi;
typedef vector<pair<int,int>>       vii;
const int MAXN   =   1e6+7;
const int inf    =   (int)1e7;
const double EPS =   1e-9;
using namespace std;


struct node{
    int vrtx;
    int wght;
    node(int v,int w){
        vrtx=v;
        wght=w;
    }
    bool operator < (const node& p) const {   return wght >p.wght;}
};

int n;
int e;

int dist[100000];
void Dijkstra(int src,vector< pair<int,int> >graph[]){
    bool visit[100000];
    for(int i=1;i<=n;i++){
        dist[i]=inf;
        visit[i]=false;
    }

    priority_queue <node> pq;
    pq.push(node(src,0));
    dist[src]=0;
    while(!pq.empty()){
        node tp=pq.top();
        pq.pop();
        int W=tp.wght;
        int V=tp.vrtx;
        if(visit[V]==true) continue;
        visit[V]=true;

        for(int i=0;i<graph[V].size();i++){
            pair<int,int> pr = graph[V][i];
            int u=pr.first;
            int w=pr.second;
            if(dist[u]>W+w){
                dist[u]=w+W;
                pq.push(node(u,w+W));
            }
        }
    }
}


int main()
{
	
	int i,j,k,x,y,w;
	vector< pair<int,int> > gra[100005];

	cin>>n>>e;
	for(i=0;i<e;i++){
		cin>>x>>y>>w;

		gra[x].push_back({y,w});
		gra[y].push_back({x,w});
	}

	Dijkstra(1,gra);

	for(i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}


	return 0;
}