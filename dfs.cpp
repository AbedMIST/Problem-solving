#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<ll> v[2005];
ll vis[2005];
ll mx=-1;

ll dfs(ll x,ll level ){
    vis[x]=1;
    mx=max(mx,level);
    for(int i=0;i<v[x].size();i++){
        ll xx=v[x][i];
        if(vis[xx]==0)
            dfs(xx,level+1);
    }
}

int main()
{
    ll a[2005],n,x,i,j,k;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        if(a[i]==-1)  v[0].push_back(i);
        else v[a[i]].push_back(i);
    }
    for(i=0;i<v[0].size();i++){
        dfs(v[0][i],1);
    }
    cout<<mx<<endl;
}
