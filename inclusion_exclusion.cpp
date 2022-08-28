// Finding co-prime numbers of an array with number x

#include<bits/stdc++.h>
#include<iostream>
#include<map>
#define PI         acos(-1)
#define ll         long long
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
using namespace std;

typedef pair<int, int>              pii;
typedef pair<long long, long long>  pll;
typedef vector<int>                 vi;
typedef vector<pair<int,int>>       vii;
const int MAXN   =   1e6+7;
const int INF    =   (int)1e7;
const double EPS =   1e-9;
using namespace std;


ll dv[200005];


vector <long long> prime;
bool sieve[200005];
void primesieve(ll n){         //O(nlog(logn))
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
    for(long long i=0;i<prime.size()&&prime[i]<=sqrtn;i++){
        if(sieve[n] == 0) break;
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                n /= prime[i];
                
            }
            primeFactors.push_back(prime[i]);
            sqrtn=sqrt(n);
        }
    }
    if(n!=1) primeFactors.push_back(n);

    //primeFactors.erase(unique(primeFactors.begin(),primeFactors.end()),primeFactors.end());
}


ll divided=0;
void subset(ll n){      //O(2^n)
    ll prod=1,i=0,c=0;
    while(n>0){
        if(n&1){
            prod= prod*primeFactors[i];
            c++;
        }
        n=n>>1;
        i++;
    }
    
    
    if(c%2)   divided+= dv[prod];  //inclusion exclusion 
    else    divided-= dv[prod];
    //cout<<prod<<"$"<<divided<<endl;

}


//n(A U B U C)=n(A)+n(B)+n(C)-n(A^B)-n(A^C)-n(A^C)+n(A^B^C)
ll a[200005];
int main(){
    //FastRead;
    ll i,j,k,n,q,x,ans;

    scanf("%lld%lld",&n,&q);

    for(j=0;j<n;j++){
        scanf("%lld",&a[j]);

        for(int i=1; i<=sqrt(a[j]); i++){
            if(a[j] % i == 0){
                if(a[j] / i == i){
                    dv[i]++;
                }
                else{
                    dv[a[j]/i]++;
                    dv[i]++;
                }
            }
        }

    }

    //for(i=0;i<=10;i++)  cout<<dv[i]<<" ";
    

    primesieve(200001);

    while(q--){
        cin>>x;

        primeFactorize(x);              //unique primeFactor
        // for(j=0;j<primeFactors.size();j++){
        //     cout<<primeFactors[j]<<" ";
        // }
        // cout<<endl;


        //Inclusion exclusion method-->finding all divided number
        ll sz= primeFactors.size();
        ll range=(1<<sz);

        divided=0;
        for(j=1;j<range;j++){       ///O(2^n)
           subset(j);
        }
        printf("%lld\n",n-divided);

        primeFactors.clear();
        
    }
    
    return 0;
}

/*
5 5
1 2 3 4 5
1
2
3
4
5 
*/