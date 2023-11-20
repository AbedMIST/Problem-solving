#include<bits/stdc++.h>
using namespace std;

#define sz 1000

vector<int> adj[sz];
int color[sz],flg;

void DFS(int u)
{
    if(flg)  return;

    for (int v : adj[u]) {

        if (color[v] == 0) {  ///unvisited

            if(color[u]==1)    color[v]=2;  ///green
            else    color[v]=1; ///red
            
            DFS(v);
        }
        else {
            if(color[v] == color[u]){  //bicoloring not possible
                flg=1;
                return;
            }
        }
    }
}

int main()
{
    int a,b,node,edge;

    while(cin>>node)
    {
        if(node==0) break;
        
        cin>>edge;
        memset(color,0,sizeof(color));

        for(int i=0;i<sz;i++) adj[i].clear();
        for(int i=0;i<edge;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        flg=0;              //initially bicoloring possible

        DFS(1);

        if(flg) printf("NOT BICOLORABLE.\n");
        else  printf("BICOLORABLE.\n");
    }
}

