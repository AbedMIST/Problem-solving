
                    /// Fuck rating, enjoy the experience.
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<map>
#define PI acos(-1)
#define ll long long
#define MAX 100005
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int MAXN= 1e5+7;


int n,a[MAXN],q,bSize;
struct bucketData{
    ll sum,st,ed;
}bucket[318];

void buildBuc(){
    for(int i=0,bCnt=0;i<n;i+=bSize,bCnt++){
        bucket[bCnt].st=i;
        bucket[bCnt].ed=i+bSize-1;
        bucket[bCnt].sum=0;
    }
    bucket[n/bSize].ed=n-1;

    for(int i=0;i<n;i++)  bucket[i/bSize].sum+=a[i];
}

ll query(int x,int y){             /// O(sqrt(n))

    int L=x/bSize;
    int R=y/bSize;
    int i;   ll ret=0;

    for(i=x;i<=min(bucket[L].ed,(ll)y);i++){  ///partial bucket
        ret+=a[i];
    }
    for(i=L+1;i<R;i++){                 ///full bucket
        ret+=bucket[i].sum;
    }
    if(L!=R){
        for(i=bucket[R].st;i<=y;i++){   ///partial bucket
            ret+=a[i];
        }
    }
    return ret;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int i,t,x,y,test,cs=1;

    scanf("%d",&test);
    while(test--){

        scanf("%d %d",&n,&q);
        bSize=sqrt(n)+1;
        for(i=0;i<n;i++)  scanf("%d",&a[i]);

        buildBuc();

        //for(i=0;i<bSize;i++)
          //  cout<<bucket[i].st<<" "<<bucket[i].ed<<" "<<bucket[i].sum<<endl;

        printf("Case %d:\n",cs);
        for(i=0;i<q;i++){       ///taking input of task
            scanf("%d",&t);
            if(t==1){
                scanf("%d",&x);
                printf("%d\n",a[x]);
                bucket[x/bSize].sum-=a[x];
                a[x]=0;
            }
            else if(t==2){      ///point update
                scanf("%d %d",&x,&y);
                a[x]+=y;
                bucket[x/bSize].sum+=y;
            }
            else{              ///range query
                scanf("%d %d",&x,&y);
                printf("%lld\n",query(x,y));
            }
            //for(j=0;j<n;j++) cout<<a[j]<<" ";
            //cout<<endl;
        }
        cs++;
    }

    return 0;
}
