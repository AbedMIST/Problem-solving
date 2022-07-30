#include<bits/stdc++.h>
#define PI acos(-1)
#define ll long long
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

char s[25][25];
ll vis[25][25],col,row,ans;
ll X[]={0,0,-1,1},Y[]={1,-1,0,0};
void dfs(ll x,ll y){
    ll i,j;
    for(i=0;i<4;i++){
        ll p,q;
        p=x+X[i],q=y+Y[i];
        if(p>=0&&p<row && q>=0&&q<col){
            if(vis[p][q]==0 && s[p][q]=='.'){
                ans++;
                vis[p][q]=1;
                dfs(p,q);
            }
        }

    }
}


int main()
{
    FastRead;
    ll n,i,j,t,a,b,cs=1,x,y;
    cin>>t;
    while(t--){
        cin>>col>>row;
        memset(vis,0,sizeof(vis));
        //getchar();
        ans=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                cin>>s[i][j];
                if(s[i][j]=='@'){
                    x=i,y=j;
                }
            }
        }
        ans++; vis[x][y]=1;
        dfs(x,y);

        printf("Case %lld: %lld\n",cs,ans);
        cs++;
    }
    return 0;
}
