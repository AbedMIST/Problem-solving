//Pallindromic substring in O(n^2)

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
const int INF    =   (int)1e7;
const double EPS =   1e-9;
using namespace std;

ll dp[11][10001][11];
ll n,a[1001],sum;

ll coin(ll i,ll s1,ll cnt)    //tabulization
{
    ll ret1,ret2;
    //cout<<cnt<<endl;
    if(i>n){
        if(cnt== n/2){
            return abs((sum-s1)-s1);
        }
        else{
            return 1e9;
        }
    }
    if(dp[i][s1][cnt]!= -1)     return dp[i][s1][cnt];


    ret1= coin(i+1,s1+a[i],cnt+1);  //taken
    ret2= coin(i+1,s1,cnt);         //not taken

    return dp[i][s1][cnt]= min(ret1,ret2);

}


void solve(){
    ll i,j,k,x;
    
    cin>>n;
    sum=0;
    memset(dp,-1,sizeof(dp));

    for(i=1;i<=n;i++){
        cin>>a[i];
        sum+= a[i];
    }

    //cout<<dp[2][7][4];
    
    ll ans = coin(1,0,0);
    cout<<ans<<endl;

}

int main(){
    //FastRead;
    ll t; cin >> t;
    while(t--) solve();
   

    return 0;
}