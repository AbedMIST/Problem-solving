
                ///Fuck rating,enjoy the experience
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define pii  pair<long long,long long>
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int MAXN   = 2e9+7;
const int INF    = (int)1e7;
const int MOD    = 1e9+7;
const double EPS = 1e-9;

ll setBit(ll n,ll pos)
{
    return   n | 1<<(pos-1);
}
bool checkBit(ll n,ll pos)
{
    return   n & 1<<(pos-1);
}
ll resetBit(ll n,ll pos)
{
    return   n & ~(1<<(pos-1));
}

ll mx[32];
int main()
{
    //freopen("wifi.in", "r", stdin);

    ll t,i,j,k,x,n,cs=1,ans;

    cin>>n;

    for(j=32;j>=1;j--){     ///checkinng every bit of array elements.

        if(checkBit(n,j))
           cout<<1;
        else
            cout<<0;
    }
    cout<<endl;

    n=setBit(n,5);
    for(j=32;j>=1;j--){     ///checkinng every bit of array elements.

        if(checkBit(n,j))
           cout<<1;
        else
            cout<<0;
    }
    cout<<endl;

    n=resetBit(n,1);
    for(j=32;j>=1;j--){     ///checkinng every bit of array elements.

        if(checkBit(n,j))
           cout<<1;
        else
            cout<<0;
    }
    cout<<endl;




    return 0;
}
