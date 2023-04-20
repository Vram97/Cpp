class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        map<int,int,greater<int>> mp;

        int sz=nums.size();

        for(int i=0;i<sz;i++){
            mp[nums[i]]=i;
            
        }

        return mp.begin()->second;
        
    }
};
