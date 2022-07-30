// Returns the length of the longest common subsequence in seq

#include<bits/stdc++.h>
#define PI acos(-1)
#define ll long long
#define mp make_pair
#define mod 100000007
#define MAX 400005
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;


int main()
{
    int C[20][20],i,j;
    string s1,s2;

    cin>>s1>>s2;
    int m=s1.size();
    int n=s2.size();
    for(i=0;i<=m;i++){
        C[i][0]=0;
    }
    for(i=0;i<=n;i++){
        C[0][i]=0;
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){       ///matches both char
                C[i][j]=C[i-1][j-1]+1;
            }
            else{
                C[i][j]=max(C[i-1][j],C[i][j-1]);
            }
        }
    }

    int l=C[m][n];
    cout<<l<<endl;

    char L[l+1];
    L[l]='\0';
    i=m,j=n;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            L[l-1]=s1[i-1];
            i--;
            j--;
            l--;
        }
        else{
            if(C[i-1][j]>C[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<L<<endl;



    return 0;
}

