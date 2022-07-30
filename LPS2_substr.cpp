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

int dp[1000][1000];

void solve(){
   int i,j,x,n;

    string str,s;
    cin>>s;
    n=s.size();
    memset(dp,0,sizeof(dp));
    int ans=0,mx=0,len,st=-1,ed=-1;

    for(i=n-1;i>=0;i--){
        for(j=i;j<n;j++){

            if(i==j){       //base case
                dp[i][j]=1;
                //ans+= dp[i][j];
                len = 1;
                if(len>=mx){
                    mx = len;
                    st = i;
                    ed = j;
                }
            }
            else if(i==j-1){       //base case
                if(s[i]==s[j]){
                    dp[i][j]=1;
                    //ans+= dp[i][j];
                    len = 2;
                    if(len>=mx){
                        mx = len;
                        st = i;
                        ed = j;
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
            else{   //general case
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];    //dependent on prev pal state
                    //ans+= dp[i][j];
                    if(dp[i][j]==1){
                        len = j-i+1;
                        if(len>=mx){
                            mx = len;
                            st = i;
                            ed = j;
                        }
                    }
                    
                }
                else{
                    dp[i][j]=0;
                }
            }

        }
    }

    //cout<<ans<<endl;
    string pal="";
    for(i=st;i<=ed;i++){
            pal+=s[i];
    }

    cout<<pal<<endl;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}