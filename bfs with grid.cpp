#include<bits/stdc++.h>
#define PI acos(-1)
#define ll long long
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct node{
    int x;
    int y;
    int cnt;
};

char s[15][15];
int vis[15][15],ans,n;
int X[]={0,0,-1,1},Y[]={1,-1,0,0};
node bfs(node start,char target ){
    memset(vis,0,sizeof(vis));
    int i,j,k;
    node temp,abed;
    vis[start.x][start.y]=1;
    queue<node>qu;
    qu.push(start);

    while(!qu.empty()){
        temp=qu.front();
        qu.pop();
        i=temp.x; j=temp.y;
        if(s[i][j]==target)
            return temp;

        for(k=0;k<4;k++){
            int p,q;
            p=i+X[k],q=j+Y[k];

            if(p>=0&&p<n && q>=0&&q<n){
                if(vis[p][q]==0 && (s[p][q]=='.'|| s[p][q]==target)){
                    vis[p][q]=1;
                    abed.x=p; abed.y=q;
                    abed.cnt =temp.cnt+1;
                    qu.push(abed);

                }
            }
        }
    }
    temp.cnt=INT_MAX;
    return temp;

}


int main()
{
    //FastRead;
    int i,j,t,a,b,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        memset(vis,0,sizeof(vis));
        //getchar();
        node temp;
        ans=0; ll k=0,dis,sum=0,l=-1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>s[i][j];
                if(s[i][j]=='A'){
                    temp.x=i;
                    temp.y=j;
                    temp.cnt=0;
                }
                l = s[i][j] - 'A' + 1;
				k = max(k, l);

            }
        }
        //cout<<temp.x<<" "<<temp.y<<" "<<k;
        for(i=0;i<k;i++){
            char target='A'+ i;
            temp.cnt=0;
            node dis=bfs(temp,target);
            if(dis.cnt==INT_MAX)  ///target not found
            {
                break;
            }

            s[dis.x][dis.y]='.';
            sum+=dis.cnt;
            temp=dis;
        }
        if(i==k)
            printf("Case %d: %d\n",cs,sum);
        else
            printf("Case %d: Impossible\n",cs);
        cs++;
    }
    return 0;
}
