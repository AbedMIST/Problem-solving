
#include<bits/stdc++.h>
#define PI acos(-1)
#define ll long long
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<ll> gra[100005];
ll vis[100005],black,red;
void bfs(int shuru)
{
    black=0,red=0;
    vis[shuru] = 1; black++;
    queue<int> q;
    q.push(shuru);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0;i<gra[x].size();i++)
        {
            int xx = gra[x][i];

            if(vis[xx]==0)
            {
                if(vis[x]==1) {
                    vis[xx]=2;
                    red++;
                }
                else{
                    vis[xx]=1; black++;
                }
                q.push(xx); ///for level-wise visit
            }

        }
    }
}

int main()
{
    FastRead;
    ll n,i,j,ans,t,x,a,b,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        memset(vis,0,sizeof(vis));
        for(i=0;i<=20005;i++)
            gra[i].clear();
        for(i=0;i<n;i++){
            cin>>a>>b;
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
        ans=0;
        for(i=0;i<20005;i++){
            if( vis[i]==0 && !gra[i].empty()){
                 bfs(i) ;
                ans+=max(black,red);
            }
        }

        printf("Case %lld: %lld\n",cs,ans);
        cs++;
    }
    return 0;
}
