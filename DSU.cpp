//Disjoint set union to find cycle
//representing set as tree

#include<bits/stdc++.h>
#include<iostream>
#include<map>
#define PI         acos(-1)
#define ll         long long

#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;


ll n;
ll par[100000],sz[100000];


void init()
{
    for(ll i=0;i<=n;i++){
        par[i]=i;
        sz[i]=1;	//sz only matters for roots
    }
}

ll find(ll v)
{
	if(par[v]==v)	return v;	//parent found

	return par[v]= find(par[v]);		//path compression
}

void Union(ll a,ll b)
{
	//two roots
	a = find(a);
	b = find(b);

	if(a==b){
		cout<<"Cycle found"<<endl;
	}	
	else{					//union by sz
		if(sz[a]<sz[b])
			swap(a,b);
		par[b]= a;		//assigning tree b into a
		sz[a]+= sz[b];
	}
}



int main()
{
	ll i,j,k;
	cin>>n>>k;

	init();
	
	while(k--){
		ll u,v;
		cin>>u>>v;
		Union(u,v);
	}

	ll con_component=0;
	for(i=1;i<=n;i++){
		if(find(i)==i){		//root found
			con_component++;
		}
	}

	cout<<con_component<<endl;

}

/*
8 9
1 2
3 4
1 3
2 4
2 5
5 6
6 8
7 8
5 7
*/