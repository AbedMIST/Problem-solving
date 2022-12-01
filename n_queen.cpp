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



int n;
int chess_board[1000][1000];
int cnt;
void init()
{
    cnt=0;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            chess_board[i][j]=0;
        }
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<chess_board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
int is_safe(int r,int c)
{
    int i=r;
    int j=c;
    while(1)
    {
        if(i==0)
            {break;}
        if(chess_board[i][j]==1)
            {return 0;}

        i--;

    }
    i=r;
    j=c;
    while(1)
    {
        if(i==0 || j==0)
            {break;}
        if(chess_board[i][j]==1)
            {return 0;}

        i--;
        j--;


    }
    i=r;
    j=c;
    while(1)
    {
        if(i==0 || j==n+1)
            {break;}
        if(chess_board[i][j]==1)  //attack position, not safe
        {
            return 0;
        }

        i--;
        j++;


    }
    return 1;   //no attack, safe found
}
void nqueen(int i)
{
    if(i==n+1)  //base case
    {
        cnt++;
        print();
    }
    for(int j=1;j<=n;j++)
    {
        if(is_safe(i,j)==1)
        {
            chess_board[i][j]=1;
            nqueen(i+1);
            chess_board[i][j]=0;
        }
    }

}
signed main()
{
    cin>>n;
    init();
    nqueen(1);
    cout<<cnt;


}