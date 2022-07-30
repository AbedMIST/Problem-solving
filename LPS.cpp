// Returns the length of the longest palindromic subsequence in seq

#include<bits/stdc++.h>
#define PI acos(-1)
#define ll long long
#define mp make_pair
#define mod 100000007
#define MAX 400005
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;


int lps(string str)
{
   int n = str.size();
   int i, j, len;
   int L[n][n];  // Create a table to store results of subproblems
 
 
   for (i = 0; i < n; i++)
      L[i][i] = 1;
 
    for (len=2; len<=n; len++)
    {
        for (i=0; i<n-len+1; i++)
        {
            j = i+len-1;
            if (str[i] == str[j] && len == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    return L[0][n-1];
}
 

int main()
{
    string s = "GEEKSFORGEEKS";
    int n = s.size();
    printf ("The length of the LPS is %d", lps(s));

    return 0;
}