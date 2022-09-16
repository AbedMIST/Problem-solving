                ///Fuck rating,enjoy the experience

#include<bits/stdc++.h>
#include<iostream>
#include<map>
#define PI         acos(-1)
#define ll         long long
#define int         long long
#define mod        1000000007  
#define pb         push_back

#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

#define       MAX       500005
#define       INF       1<<30
#define       EPS       1e-9
typedef pair<int, int>              pii;
typedef pair<long long, long long>  pll;
typedef vector<int>                 vi;
typedef vector<pair<int,int>>       vii;
const int inf = 1e18+2; 

int a[201][201],n,m;

void dfs(vector<vector<bool>> &vis,int i,int j)
{
    // if(r<0 || r>=n || c<0 || c>m ||  vis[r][c] || a[r][c]<prev) //invalid cell
    //     return;

    vis[i][j] = true;
    //up
    if (i-1 >= 0 && vis[i-1][j] != true && a[i-1][j]>=a[i][j])
        dfs(vis, i-1, j);
    //down
    if (i+1 < n && vis[i+1][j] != true && a[i+1][j]>=a[i][j])
        dfs(vis, i+1, j);
    //left
    if (j-1 >= 0 && vis[i][j-1] != true && a[i][j-1]>=a[i][j])
        dfs(vis, i, j-1);
    //right
    if (j+1 <m && vis[i][j+1] != true && a[i][j+1]>=a[i][j])
        dfs(vis, i, j+1);

}


signed main()
{
    
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    vector<vector<bool>> pac( n+1 , vector<bool> (m+1, 0)); 
    vector<vector<bool>> atl( n+1 , vector<bool> (m+1, 0)); 

    for(i=0;i<m;i++){       
        dfs(pac,0,i);       //for pacific route
        dfs(atl,n-1,i);   //for atlantic route
    }

    for(i=0;i<n;i++){       
        dfs(pac,i,0);
        dfs(atl,i,m-1);
    }


    vector<vector<int>> ans; //all possible coordinates
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(pac[i][j] && atl[i][j]){
                ans.push_back({i,j});
                cout<<i<<" "<<j<<endl;
            }
        }
    }

    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         cout<<pac[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}