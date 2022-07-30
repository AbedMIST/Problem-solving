
                    /// Fuck rating, enjoy the experience.
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int MAXN= 1e5+7;
const int INF = (int)1e7;

ll a[MAX],n;
struct nodeData{
    ll sum,lazy;
    bool hasLazy;
}tree[4*MAX +10];

void init(ll node,ll st,ll ed)  ///initialize segment tree
{
    ll left,right,mid;
    if(st==ed){
       tree[node].sum= a[st];
       return;
    }

    left=2*node; right=2*node+1;    ///left and right child
    mid=(st+ed)/2;
    init(left,st,mid);
    init(right,mid+1,ed);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].lazy=0;
    tree[node].hasLazy=false;
}

void propagate(ll node,ll st,ll ed)
{
    ll left,right,mid;
    if(tree[node].hasLazy== false) return;

    left=2*node; right=2*node+1;
    mid=(st+ed)/2;
    tree[left].sum+=(mid-st+1)*tree[node].lazy;     ///if the node has lazy value
    tree[left].lazy+=tree[node].lazy;
    tree[left].hasLazy=true;
    tree[right].sum+=(ed-(mid+1)+1)*tree[node].lazy;
    tree[right].lazy+=tree[node].lazy;
    tree[right].hasLazy=true;

    tree[node].lazy=0;
    tree[node].hasLazy=false;

}
ll query(ll node,ll st,ll ed,ll i,ll j)    ///finding sum from i->j range
{
    ll left,right,mid;
    if(i<=st && ed<=j){     ///if full range is under query
       return tree[node].sum;
    }
    left=2*node; right=2*node+1;
    mid=(st+ed)/2;

    ll ret=0,ret1=0,ret2=0;
    propagate(node,st,ed);  ///increase the child value if it has lazy value..........
    if(i<=mid)
        ret1=query(left,st,mid,i,j);
    if(j>=mid+1)
        ret2=query(right,mid+1,ed,i,j);

    return ret=ret1+ret2;
}

void update(ll node,ll st,ll ed,ll u,ll v,ll w)  ///adding w from u->v range.
{
    ll left,right,mid;
    if(u<=st && ed<=v){
       tree[node].sum+=(ed-st+1)*w;     ///increase only the node sum but not the child.
       tree[node].lazy+=w;
       tree[node].hasLazy=true;
       return;
    }
    left=2*node; right=2*node+1;
    mid=(st+ed)/2;

    propagate(node,st,ed);  ///increase the child value if it has lazy value..........
    if(u<=mid)
        update(left,st,mid,u,v,w);
    if(v>=mid+1)
        update(right,mid+1,ed,u,v,w);

    tree[node].sum=tree[left].sum+tree[right].sum;
}

int main()
{
    ll c,d,i,j,t,test,l,cnt,ans,q,x,y,v,cs=1;

    scanf("%lld",&test);
    while(test--){
        scanf("%lld %lld",&n,&q);
        for(i=0;i<n;i++){
            a[i]=0;
        }
        init(1,0,n-1);
        //for(ll i=1;i<=2*n-1;i++)
                    //cout<<tree[i].sum<<" ";

        printf("Case %lld:\n",cs);    cs++;
        for(i=0;i<q;i++){
            cin>>t>>x>>y;
            if(t==0){           ///range update
                scanf("%lld",&v);
                update(1,0,n-1,x,y,v);
                //for(ll i=1;i<=2*n-1;i++)
                    //cout<<tree[i].sum<<" ";
            }
            else{              ///range query
                printf("%lld\n",query(1,0,n-1,x,y));
            }
        }
    }

    return 0;
}
