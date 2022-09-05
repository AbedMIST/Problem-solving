//Can find any floating value in a range

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



double dist(double a, double l, double w){
     if(sqrt(a*a - (l-a)*(l-a)) > w){       //not possible
         return a+sqrt(w*w + (l-a)*(l-a));
     }
     return 2*a + w - sqrt(a*a - (l-a)*(l-a));
}

double t_search(int a, int b){  //O(log(n)), works as ternary search

    double l = 1.0*a/2, r = a;

    while(r-l > EPS){

        double m = (l+r) / 2;   //mid value
        double lft = m - 0.00001;  // need 2 more val for evaluate func -->left  m  right
        double rht = m + 0.00001;
        
        // got min ans
        if(dist(lft, a, b) > dist(m, a, b) && dist(rht, a, b) > dist(m, a, b)){
            //printf("%.10lf %.10lf %.10lf\n",dist(lft, a, b),dist(m, a, b),dist(rht, a, b));
            return dist(m, a, b);
        }
        else if(dist(lft, a, b) > dist(rht, a, b)){
            l = m;
        }
        else{
            r = m;
        }      
    }
    
    return -1.00;
}

signed main(){
    //freopen("in.txt", "r", stdin);
    FastRead;
    int l, w; 
    while(true){
        cin>>l>>w;
        if(l == 0 && w == 0) break;

        printf("%.4lf\n",t_search(l,w));
    }
    

    return 0;
}