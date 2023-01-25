#include<bits/stdc++.h>
#define PI         acos(-1)
#define ll         long long
#define int         long long
#define mod        1000000007  
#define pb         push_back

#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

#define       MAX       500005
#define       INF       1<<30    //for 32 bit
#define       EPS       1e-9
const int inf = 1e18+2; 

// par array will ocntain ith node's 2^j th parent
vector<int> gra[1005];
int lv[1005], par[1005][20];  //log2(sz)+1=10
int cs=1,n,MaxPow;


void dfs(int x,int p,int level)  //for level and parent
{
	par[x][0] = p;   //1st parent
	lv[x] = level;

	for(int i=0;i<gra[x].size();i++){
		int xx = gra[x][i];
		if(xx!=p){
			dfs(xx,x,level+1);    //for all child node
		}
	}
}

void build()  //creating binary lifted parent for the tree
{
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=MaxPow;j++){
			par[i][j] =-1;
		}
	}

	dfs(1,-1,1);  //root 1

	for(j=1;j<=MaxPow;j++){  //VVI(binary lifting of 2^j parent)
		for(i=1;i<=n;i++){
			if(par[i][j-1]!=-1)               //mandatory check
				par[i][j] = par[par[i][j-1]][j-1];
		}
	}
}

int lca(int a,int b)   //O(log(n))
{
	int i,j;
	if(lv[a]<lv[b]) swap(a,b);
	int k = lv[a]-lv[b];

	for(j=MaxPow-1;j>=0;j--){  //finding kth ancestor of 'a' to make a and b in same level
		if((1<<j)<=k){
			a = par[a][j];
			k-= (1<<j);
		}
	}
	if(a==b)  return a;

	for(j=MaxPow-1;j>=0;j--){ //goes to the lowest ancestor as close as possble
		if(par[a][j]!=par[b][j]){
			a = par[a][j];
			b = par[b][j];
		}
	}
	return par[a][0];  //lowest ancestor
}


void solve()
{
    int i,j,m,x,y,q;
    cin>>n;
    MaxPow=log2(n)+1;
    //memset(par,-1,sizeof(par));
    memset(lv,0,sizeof(lv));
    for(i=0;i<1005;i++)
        gra[i].clear();

    for(i=1;i<=n;i++){
    	cin>>m;
    	for(j=0;j<m;j++){  //all child node
    		cin>>x;
    		gra[i].push_back(x);
    	}
    }


    build();  //preprocessing for binary lifting
    // for(i=0;i<=n;i++){
    // 	cout<<i<<"--"<<lv[i]<<" "<<par[i][0]<<endl;
    // }

    cin>>q;
    printf("Case %lld:\n",cs);
    while(q--){
    	cin>>x>>y;
    	int ans = lca(x,y);
    	printf("%lld\n",ans);
    }
  	cs++;
}

signed main() {
    //FastRead;
    int t; cin>>t;
    while(t--) solve();

    return 0;
}