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
    ll i,j,k,n;

    cin>>n;
    vector<ll> v(n+1,0);

    for(i=1;i<=n;i++){
        cin>>v[i];
    }

    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end()); //unique elements

    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<ll>::iterator lower, upper;
    lower = lower_bound(v.begin(),v.end(),4);
    upper = upper_bound(v.begin(),v.end(),2);
    cout<<(lower-v.begin()+1)<<" "<<(upper-v.begin())<<endl;


    cout<<"---------------------------"<<endl;
    //vector<ll> v[100];
    vector< vector<ll> > vec2;

    vec2.push_back({4,5,6});
    vec2.push_back({1,2,3});
    vec2.push_back(v);
    vec2.push_back({2,2,3,7});

    // for (int i = 0; i < n; i++) {
        
    //     vector<int> v1;
    //     for (int j = 0; j < n; j++) {
    //         v1.push_back(j);
    //     }

    //     vec.push_back(v1);
    // }


    // Displaying the 2D vector
    for (int i = 0; i < vec2.size(); i++) {
        for (int j = 0; j < vec2[i].size(); j++)
            cout << vec2[i][j] << " ";
        cout << endl;
    }
    

    return 0;
}