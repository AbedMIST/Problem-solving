
                ///Fuck rating,enjoy the experience
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI         acos(-1)
#define ll         long long
#define int        long long
#define MAX        100005
#define mod        1000000007  
#define pb         push_back
#define MP(x, y)   make_pair(x, y)
#define ff         first
#define ss         second
#define rep(i,n)   for(int i=0;i++<n;)
#define sci(a)     scanf("%d",&a)
#define scl(a)     scanf("%lld",&a)
#define b_s(a,b)   binary_search(a.begin(),a.end(),b)
#define l_b(a,b)   lower_bound(a.begin(),a.end(),b)
#define u_b(a,b)   upper_bound(a.begin(),a.end(),b)
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
#define Dbug1(x)        cout << #x << " is " << x << endl;
#define Dbug2(x,y)      cout << #x << " is " << x << "    " << #y << " is " << y << endl ;
#define Dbug3(x,y,z)    cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << endl;
using namespace std;

typedef pair<int, int>              pii;
typedef pair<long long, long long>  pll;
typedef vector<int>                 vi;
typedef vector<pair<int,int>>       vii;
#define       MAX       500005
#define       INF       1<<30
#define       EPS       1e-9
const   int   inf    = 1e18+2; 



long long int gcd(long long int a,long long int b)
{
    long long int t;
    while(b)
    {
        t=a;
        a=b;
        b=t%b;
    }
    return a;
}
long long lcm(long long a,long long b)
{
    int x=(a*b)/gcd(a,b);
    return x;
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
    //return (a.second < b.second);
    if(a.second < b.second)
        return true;
    else
        return false;
}

string converttostring(long long n){
    string s;
    stringstream ss;
    ss << n;
    s = ss.str();

    return s;
}
int checkDiffDigits(string str){
    for(int i = 0; i<str.size(); i++){
        for(int j = i+1; j<str.size();j++){
            if(str[i] == str[j]){
                return false;
                break;
            }
        }
    }
    return true;
}

ll power(ll a , ll n, ll m)
{
    a %= m;
    ll result = 1;
 
    while(n)
    {
        if(n & 1) result = (result * a) % m;
 
        n >>= 1;            ///for even
        a = (a * a) % m;
    }
 
    return result;
}
vector <long long> prime;
bool sieve[1000001];
void primesieve(ll n){      //O(nlog(logn))
    sieve[0] = sieve[1] = 1;
    prime.push_back(2);
    for(long long i = 4; i<=n; i+=2){
        sieve[i] = 1;
    }
    long long sqrtn = sqrt(n);
    for(long long i = 3; i<= sqrtn; i+=2){
        if(sieve[i] == 0){
            for(long long j = i*i; j<=n; j+=2*i){///cutting the multiple of prime---
                sieve[j] = 1;
            }
        }
    }
    for(long long i=3;i<=n;i+=2){
        if(sieve[i] == 0) prime.push_back(i);
    }
}
vector <long long> primeFactors;
void primeFactorize(ll n){      //O(log(n))
    ll sqrtn = sqrt(n);
    primesieve(n);              //need to cut 
    for(long long i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
        if(sieve[n] == 0) break;
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                n /= prime[i];
                primeFactors.push_back(prime[i]);
            }
            sqrtn=sqrt(n);
        }
    }
    if(n!=1) primeFactors.push_back(n);
}
int NOD(int n){
    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int p = 0;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++;
            res *= p;  //NOD=(pow1+1)*(pow2+1)*(pow3+1)......(combination)
        }
    }
    if ( n != 1 ) {
        res *= 2;
    }
    return res;
}
int SOD( int n ) {
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum; //SOD=(p1^0+p1^1+p1^2+..)*(p2^0+p2^1+p2^2+...)*....
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); // Need to multiply (p^0+p^1)
    }
    return res;
}
int euler_phi(int n) {      //O(sqrt(n)) -->co-prime to n 
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;   //phi(n)=n*(1-1/p1)(1-1/p2)..(1-1/p^k)
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int binarySearch(int arr[], int l, int r, int x)    //O(log(n))
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

vector<ll> gra[100005];
ll vis[100005];
void bfs(int shuru)     //O(V+E)
{
    vis[shuru] = 1;
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
                vis[xx]=1;
                q.push(xx); ///for level-wise visit
            }

        }
    }
}

vector<ll> v[2005];
//ll vis[2005];
ll mx=-1;

ll dfs(ll x,ll level ){     //O(V+E)
    vis[x]=1;
    mx=max(mx,level);
    for(int i=0;i<v[x].size();i++){
        ll xx=v[x][i];
        if(vis[xx]==0)
            dfs(xx,level+1);
    }
}


signed main()
{
     FastRead;
     //freopen("input.txt","r",stdin);

     primeFactorize(100);
     for(int i=0;i<primeFactors.size();i++){
        cout<<primeFactors[i]<<" ";

     }

}
