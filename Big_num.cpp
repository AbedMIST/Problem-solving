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
 
 
ll power(ll bs,ll n)
{
    ll res=1;
    while(n){
        if(n%2){              ///power odd
            res= (res*bs)%10;
            n--;
        }
        else{               ///power even
            bs= (bs*bs)%10;
            n/=2;
        }
    }
    return res;
}

int main()
{
    //FastRead;
    //freopen("input.txt","r",stdin);
    ll i,j,k,t,x,y,n,m,cs=1,ans;
 
    cin>>n;
    ans= power(8,n);
    cout<<ans<<endl;
 
    return 0;
}