//coin change min difference 

#include<bits/stdc++.h>
#include<iostream>
#include<map>
#define PI         acos(-1)
#define ll         long long
#define int        long long
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
const int INF    =   (int)1e7;
const double EPS =   1e-9;


int wt[105];
int dp[105][50000+5];


int knapSack(int i,int w)
{
    if (i == 0 || w == 0) return 0;
    if(dp[i][w]!=0) return dp[i][w];

    int ret1=0,ret2=0;
    if(w-wt[i]>=0)
        ret1= wt[i] + knapSack(i-1,w-wt[i]);    ///Taken

    ret2= knapSack(i-1,w);          ///Not taken
    return dp[i][w]=max(ret1,ret2);

}


void solve(){
    int i,j,n,x;
    
    cin>>n;
    int sum=0;

    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++){
        cin>>wt[i];
        sum+= wt[i];
    }
    
    int ans = abs(sum - 2*knapSack(n,sum/2));
    cout<<ans<<endl;

}

signed main(){
    FastRead;
    int t; cin >> t;
    while(t--) solve();
   

    return 0;
}
