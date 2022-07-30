#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
vector<ll>v;
ll OR(ll n){
    ll sum=0,i=0;
    while(n>0){
        if(n&1) sum=sum+v[i];
        n=n>>1;
        i++;
    }
    return sum;
}

int main()
{
    ll n,m,x,i,j,k,t;
    cin>>t;
    while(t--){
        ll ans=0,flag=0;
        cin>>n>>m;
        for(i=0;i<n;i++){
            cin>>x;
            v.push_back(x);
        }

        int range=(1<<n);
        for(int i=0;i<range;i++){       ///O(2^n)
           ans=OR(i);
           if(ans==m){
            cout<<"Yes"<<endl;flag=1;
            break;
           }
        }
        if(flag==0)
            cout<<"No"<<endl;
        v.clear();
    }
    //cout<<ans;
    return 0;
}




