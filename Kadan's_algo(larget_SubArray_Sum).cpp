class Solution {
public:
    int maxSubArray(vector<int>& nums) { //Kadan's algo, O(n)
        
        int i,j;
        int sum=0;
        int ans = INT_MIN;
        for(i=0;i<nums.size();i++){
            sum+= nums[i];
            ans = max(ans,sum);

            if(sum<0)   sum=0; //no better is possible with prev
        }
        
        return ans;
    }
};
