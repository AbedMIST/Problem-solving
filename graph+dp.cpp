                ///Fuck rating,enjoy the experience
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int MAXN   = 1e6+7;
const int INF    = (int)1e7;
const int MOD    = 1e9+7;
const double EPS = 1e-9;
typedef  pair<int,int>  pii;
typedef  pair<long long,long long>  pll;

vector<ll>adj[1005];
ll parent[1005],dp[1005][2];

ll guard(ll par,bool flag)
{

    if(dp[par][flag]!=-1)   return dp[par][flag];

    ll i,j,ret1=0;
    if(flag)    ret1++;

    for(ll child :adj[par]){
        if(parent[par]==child)  continue;

        parent[child]=par;

       if(flag){
            ret1+= min(guard(child,0),guard(child,1));
       }
       else{
            ret1+= guard(child,1);
       }
    }
    return dp[par][flag]=ret1;
}


int main()
{
    //FastRead;
    ll n,i,j,k,ans,t,x,cs=1,a,b;

    //cin>>t;
    while(cin>>n){
        if(n==0)    break;

        memset(parent,-1,sizeof(parent));
        memset(dp,-1,sizeof(dp));
        for(i=0;i<=1005;i++)
            adj[i].clear();

        for(i=0;i<n;i++){
            cin>>x;
            for(j=0;j<x;j++){
                cin>>a;
                adj[i+1].push_back(a);
            }
        }

        ans= min(guard(1,1),guard(1,0));
        if(n==1)    ans=1;

        printf("%lld\n",ans);
    }

    return 0;
}

