#include <bits/stdc++.h>

using namespace std;

int main() {
        int i,j,k,n,x,target;
        vector<int>nums;
        
        cin>>n;
        for(i=0;i<n;i++){
            cin>>x;
            nums.push_back(x);
        }
    
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        
        for(i=0;i<n-2;i++){   // O(n^2)
        
            if(i>0 && nums[i-1]==nums[i])   continue;
            int l,r,sum;
            l = i+1;
            r = n-1;

            
            while(l<r){
                //cout<<l<<" "<<r<<endl;
                sum= nums[i]+nums[l]+nums[r];   // 1 number fixed
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++; r--;
                }
                else if(sum<0)  l++;
                else    r--;
            }
            
        }
        
     sort(ans.begin(),ans.end());    
     ans.erase(unique(ans.begin(), ans.end()), ans.end());
     
     for(auto x : ans){
         for(auto xx : x){
             cout<<xx<<" ";
         }
         cout<<endl;
     }
   
        
}