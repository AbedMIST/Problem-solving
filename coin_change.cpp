#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll int
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

ll coin[]={50,25,10,5,1};
ll dp[10][7500],make;
int dp1[10][7500];
int cnt = 1;
ll call(int i,int amount)
{
    if(i>=5){
        if(amount==make) return 1;
        else return 0;
    }
    if(dp1[i][amount]==cnt) return dp[i][amount];

    dp1[i][amount]=cnt;

    ll ret1=0,ret2=0;
    if(amount+coin[i] <= make) ret1=call(i,amount+coin[i]); ///taking the coin
    ret2=call(i+1,amount);   ///not taking the coin and go to next
    return dp[i][amount]=ret1+ret2;
}

int main()
{
    ll i,j,k;

    while(scanf("%lld",&make)!=EOF){
        cnt++;
        ll x=call(0,0);
        printf("%lld\n",x);    ///number of ways to make definite tk(can take any time of a coin)
    }

    return 0;
}
