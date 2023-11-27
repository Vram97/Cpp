class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int curr=0;
        int max_val=INT_MIN;

        for(int x:nums){
            if(x>max_val){
                max_val=x;
            }

            if(curr+x<0){
                curr=0;
            }
            else{
                curr+=x;
            }

            if(curr>ans){
                ans=curr;
            }
        }

        return (max_val<0)?max_val:ans;



    }
};
