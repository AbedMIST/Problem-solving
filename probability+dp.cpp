                    /// Fuck rating, enjoy the experience.
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define rep(i,n) for(int i=0;i++<n;)
#define sci(a)   scanf("%d",&a)
#define scl(a)   scanf("%lld",&a)
#define b_s(a,b) binary_search(a.begin(),a.end(),b)
#define l_b(a,b) lower_bound(a.begin(),a.end(),b)
#define u_b(a,b) upper_bound(a.begin(),a.end(),b)
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef pair<int, int>   pii;
typedef pair<long long, long long>   pll;
typedef vector<int>     vi;
typedef vector<pair<int,int>>    vii;
const int MAXN   = 1e6+7;
const int INF    = (int)1e7;
const double EPS = 1e-9;

///dp[i][j]= dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);

double dp[1005][1005],p[1005];
double probability(ll n,ll k)
{
    ll i,j;

    for(i=0;i<=k;i++)   dp[0][i]=1.0;

    for(i=1;i<=n;i++){
        dp[i][0]= dp[i-1][0]*(1-p[i]);

        for(j=1;j<=k && j<=i;j++){
            /// dp[i][j] --> probability of getting j heads in i trials.
            if(i==j)  
                dp[i][j]= dp[i-1][j-1]*p[i] ;  
            else
                dp[i][j]= dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);  ///FOCUS
        }
    }
    
    return dp[n][k];
}


int main()
{
    //FastRead;
    //freopen("input.txt","r",stdin);
    ll i,j,k,t,x,y,n,cs=1;
    double ans;

    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));

    	cin>>n>>k;
        for(i=1;i<=n;i++)    cin>>p[i];

        ans= probability(n,k);
        cout<<ans<<endl;
        // for(i=0;i<=n;i++){
        //     for(j=0;j<=k;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

    }

    return 0;
}