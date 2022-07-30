#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define mp make_pair
#define mod 100000007
#define MAX 400005
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;


int wt[1000],val[1000],cap,n;
int dp[1000][1000];


int knapSack(int i,int w)
{
    if (i == 0 || w == 0) return 0;
    if(dp[i][w]!=0) return dp[i][w];

    int ret1=0,ret2=0;
    if(w-wt[i]>=0)
        ret1=val[i] + knapSack(i-1,w-wt[i]);    ///Taken

    ret2= knapSack(i-1,w);          ///Not taken
    return dp[i][w]=max(ret1,ret2);

}


int main()
{
    int i,j,k;
    cin>>n>>cap;
    //memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<knapSack(n,cap) <<endl;



    return 0;
}
/*
4 5
2 12
1 10
3 20
2 15
*/

