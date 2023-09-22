class Solution {
public:
    int majorityElement(vector<int>& nums) { //O(n)->Moore's voting algo
        
        int cnt=0,majority=0;
        for(int n:nums){
            if(cnt==0)
                majority = n;
            
            if(n==majority)  //same maj found
                cnt++;
            else
                cnt--;
        }

        return majority;
    }
};
