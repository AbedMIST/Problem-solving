
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>   pii;



int n;
vector<int> adj[1001];
int level[1001], parent[1001];
vector<pii>vp;
vector< vector<int>> ans;

void dfs_lvl(int node,int par,int lvl){
    level[node] = lvl;
    parent[node] = par;

    for(int it:adj[node]){	//DFS
        if(it!=par){
            dfs_lvl(it,node,lvl+1);
        }
    }
}

void printpath(int node){

	if(parent[node]!=-1)	printpath(parent[node]);
	cout<<node<<" ";
}



vector<int>temp;
int vis[1001];
void call(int node,int par){  //using dfs
    temp.emplace_back(node);
    vis[node]=1;
    for(int it:adj[node]){
        if(!vis[it] and it!=par){
            call(it,node);
            break;
        }
    }
}

void all_path(int root){	//all possible path without intersecting

	for(int i=1;i<=n;i++){
        vp.emplace_back(level[i],i);
    }

    sort(vp.begin(), vp.end());

    for(auto it:vp){
        int node = it.second;
        if(!vis[node]){
            temp.clear();
            call(node,-1);
            ans.push_back(temp);
        }
    }

    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it.size()<<endl;
        for(auto itt:it) cout<<itt<<' ';
            cout<<endl;
    }

    cout<<endl;
}

int main()
{
	// nodes from 1 to n
	int i,j,k,x,y,root;
	cin>>n>>root;
	
	for(i=0;i<n-1;i++){		//edges = n-1 (for tree)
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs_lvl(root,-1,1);

	printpath(5);
	cout<<endl;

	all_path(root);  //without intersecting
	


	return 0;
}
