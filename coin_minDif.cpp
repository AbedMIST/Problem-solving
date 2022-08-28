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


ll min_dif(ll n,ll sum,vector<ll> &a)    //tabulization
{
    ll idx,target,i,j,k;

    k = sum;
    vector<vector<bool>> dp(n, vector<bool>(k+1,0));

    for(i=0;i<n;i++)    dp[i][0]= true;     //base case

    if(a[0]<=k)    dp[0][a[0]] = true;

    for(idx=1;idx<n;idx++){                 //subset sum to k
        for(target=1; target<=k;target++){

            bool notTake= dp[idx-1][target];

            bool take = false;
            if(target>=a[idx])
                take = dp[idx-1][target-a[idx]];   

            dp[idx][target] = take | notTake;   //only true or false
        }
    }
    //return dp[n-1][k];

    ll s1,mn = 1e9;
    for(s1=0; s1<= sum/2 ; s1++){   //other half will repeat the subset
        if(dp[n-1][s1]){                    //all possible sum--> FOCUS
            mn = min(mn, abs((sum-s1)-s1));
        }
    }

    return mn;

}


void solve(){
    ll i,j,n,x;
    
    cin>>n;
    vector<ll> v(n,0);
    ll sum=0;

    for(i=0;i<n;i++){
        cin>>v[i];
        sum+= v[i];
    }
    
    ll ans = min_dif(n,sum,v);
    cout<<ans<<endl;

}

int main(){
    //FastRead;
    ll t; cin >> t;
    while(t--) solve();
   

    return 0;
}