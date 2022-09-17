
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int u, vector<int> adj[],vector<bool>&color, vector<bool>&curSt) {
        color[u] = 1;          ///grey
        curSt[u] = 1;
        
        for (int v : adj[u]) {
            
            if (color[v] == 0) {
                if (dfs(v, adj, color,curSt)) //if one return true,all return true
                    return true;
            } 
            else if (color[v]==1 && curSt[v]==1) {   ///has cycle***
                return true;
            }
        }
        
        curSt[u] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        int i,j;
        vector<bool> color(V,0);
	    vector<bool> curSt(V,0);
        
        for(i=0;i<V;i++){
            if(color[i]==0){
                if(dfs(i,adj,color,curSt))  return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends