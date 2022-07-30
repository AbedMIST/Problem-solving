            /// Fuck rating, enjoy the experience.
/// finding number of elements less than k in any range ...
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define mod 1000000007
#define pb push_back
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int MAXN= 1e5+7;
const int INF = (int)1e7;


ll a[MAX],n;
vector<ll> tree[4*MAX+10];

void build(ll node,ll st,ll ed)
{
    ll left,right,mid;
    if(st==ed){
        tree[node].push_back(a[st]);
        return;
    }

    left=2*node; right=2*node+1;    ///left and right child
    mid=(st+ed)/2;
    build(left,st,mid);
    build(right,mid+1,ed);

    ll i=0,j=0;            ///concate left and right child vector
    while(i<tree[left].size() && j<tree[right].size()){
        if(tree[left][i] <= tree[right][j]){
            tree[node].push_back(tree[left][i]); i++;
        }
        else{
            tree[node].push_back(tree[right][j]); j++;
        }
    }
    while(i<tree[left].size()){
        tree[node].push_back(tree[left][i]); i++;
    }
    while(j<tree[right].size()){
        tree[node].push_back(tree[right][j]); j++;
    }
}

ll query(ll node,ll st,ll ed,ll i,ll j,ll k)
{
    ll left,right,mid;
    if(i<=st && ed<=j){     ///if full range is under query
       ll up= upper_bound(tree[node].begin(),tree[node].end(),k-1) -tree[node].begin();  ///finding elements less than k.
       return up;
    }
    if(i>ed || j<st)   return 0;

    left=2*node; right=2*node+1;    ///left and right child
    mid=(st+ed)/2;

    ll ret=0,ret1=0,ret2=0;
    if(i<=mid)
        ret1=query(left,st,mid,i,j,k);
    if(j>=mid+1)
        ret2=query(right,mid+1,ed,i,j,k);

    return ret=ret1+ret2;
}

int main()
{
    ll i,j,k,n,m,q,t,ans,l,r;

    cin>>n;
    for(i=0;i<n;i++)    cin>>a[i];

    build(1,0,n-1);
//    for(i=0;i<tree[1].size();i++){
//        cout<<tree[1][i]<<" ";
//    }


    cin>>q;
    for(i=0;i<q;i++){
        cin>>l>>r>>k;
        printf("%lld\n",query(1,0,n-1,l-1,r-1,k));
    }


}
