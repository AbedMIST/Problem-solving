#include<bits/stdc++.h>
#define PI         acos(-1)
#define ll         long long
#define MAX        100005
#define mod        1000000007  
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef pair<int,int>   pii;


struct hash_pair {							//operator overloading
   size_t operator()(const pair<int,int>&x)const{
   		return x.first * 23 + x.second;
   }
};
// we are doing double hash, so we are using two base and two mod
#define sz 20007
#define base1 3207
#define base2 3721
#define mod1 1000003999
#define mod2 1000000861
int pow1[sz+1];
int pow2[sz+1];


void calculate_pow(){
    pow1[0] = 1; pow2[0] = 1;
    for(int i=1; i<sz; i++){
        pow1[i] = (pow1[i-1] *1LL* base1) % mod1;
        pow2[i] = (pow2[i-1] *1LL* base2) % mod2;
    }
}

class HASH{
	int hashV1; 
	int hashV2;
    int prefix_hash1[sz+1]; // size = len of string
    int prefix_hash2[sz+1];

    int calculate_hash(int h,int m,int b,char c){
    	int ret;
    	ret = ((h*1LL*b)%m + (c+1))%m;	//FOCUS
    	return ret;		// adding 1 so that 0 does not occur
    }

public:
	HASH(){
		hashV1=0, hashV2=0;
	}
	void reset(){
        hashV1 = 0; hashV2 = 0;
    }

	void pref_hash_table(string s){
		int len = s.size();
		int i,j;

		for(i=0;i<len;i++){
			hashV1 = calculate_hash(hashV1, mod1, base1, s[i]);	//hashV of(s[i])+prev_hashV
            hashV2 = calculate_hash(hashV2, mod2, base2, s[i]);
            prefix_hash1[i] = hashV1;
            prefix_hash2[i] = hashV2;
		}
	}

	// double hash value for a whole string
    pii hash_total_string(string s){
        hashV1 = 0; hashV2 = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            hashV1 = calculate_hash(hashV1, mod1, base1, s[i]);
            hashV2 = calculate_hash(hashV2, mod2, base2, s[i]);
        }
        pii p = {hashV1,hashV2};
        return p;
    }

    //double hash value of any substring(can match substr in O(1))
    pii hash_val_substr(int i,int j){		// 0 index based query
        pii pr = {prefix_hash1[j], prefix_hash2[j]};
        if(i != 0)
            pr = {(mod1*1LL + ((prefix_hash1[j] - prefix_hash1[i-1] *1LL* pow1[j-i+1]) % mod1)) % mod1,
                (mod2*1LL + ((prefix_hash2[j] - prefix_hash2[i-1] *1LL* pow2[j-i+1]) % mod2)) % mod2};
        return pr;
    }

};


int main()
{
	int i,j,t,n,x,y;
	HASH h;
	calculate_pow();

	cin>>t;
	while(t--){
		h.reset();
		string s;
		cin>>s>>n;

		h.pref_hash_table(s);

		for(i=0;i<n;i++){
			cin>>x>>y;
			pii p = h.hash_val(x,y);

			cout<<p.first<<" "<<p.second<<endl;
		}
	}

}