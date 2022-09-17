#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include<cstdio>
#include<cstring>

using namespace std;

int n,color[100],parent[100];
vector <int> adj[100];
int cycle_start,cycle_end;

bool dfs(int u, int par) {      //notice->no parent calc needed for directed graph
    color[u] = 1;          //grey
    for (int v : adj[u]) {
        if(v == par) continue; ///skipping edge to parent vertex
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v, parent[v])) //if one return true,all return true
                return true;
        } 
        else if (color[v] == 1) {   ///has cycle***
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    //color[u] = 2;   //black
    return false;
}
int main(){
    //freopen("inp.txt","r",stdin);
    int caseNo = 1;

    while(scanf("%d",&n)!=EOF)
    {
        int i,edges,a,b;
        //memset(visited,0,sizeof (visited));
        memset(color,0,sizeof (color));
        memset(parent,-1,sizeof (parent));
        for( i=0;i<=100;i++) adj[i].clear();

        scanf("%d",&edges);

        for(i=0;i<edges;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("#Test Case: %d\n", caseNo++);

        for(i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                if(dfs(i, -1))
                {
                    printf("Cycle Found.\n");
                    break;
                }
                else printf("Cycle Not Found.\n");
            }
        }
    }
}
