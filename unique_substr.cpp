                    /// Fuck rating, enjoy the experience.
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define rep(i,n) for(int i=0;i++<n;)
#define sci(a)   scanf("%d",&a)
#define scl(a)   scanf("%lld",&a)
#define b_s(a,b) binary_search(a.begin(),a.end(),b)
#define l_b(a,b) lower_bound(a.begin(),a.end(),b)
#define u_b(a,b) upper_bound(a.begin(),a.end(),b)
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef pair<int, int>   pii;
typedef pair<long long, long long>   pll;
typedef vector<int>     vi;
typedef vector<pair<int,int>>    vii;
const int MAXN   = 1e6+7;
const int INF    = (int)1e7;
const double EPS = 1e-9;



int main()
{
    //FastRead;
    //freopen("input.txt","r",stdin);
    int i,j,ans,n,sz;
    string str,s;

    cin>>s;
    n=s.size();
    int mx=0,len=0;
    set<char>st;
    //set<char>::iterator it;
    
    i=0;
    for(j=0;j<n;j++){   //O(n)
        
        while(st.find(s[j]) != st.end() ){  //slide window technique
            st.erase(s[i]);
            i++;
        }
        
        //unique char
        st.insert(s[j]);
        len = j-i+1;
        mx = max(mx,len);
    }
    
    cout<<mx<<endl;
    
    
    return 0;
}