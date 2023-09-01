class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int sz=nums.size();
        k=k%sz;
        unordered_map<int,int> mp;

        for(int i=0;i<sz;i++){
            int x=i+k;

            if(x<sz){
                mp[x]=nums[x];
                if(i<k){
                    nums[x]=nums[i];
                }
                else{
                    nums[x]=mp[i];
                }
            }
            else{
                if(i<k){
                    nums[x-sz]=nums[i];
                }
                else{
                    nums[x-sz]=mp[i];
                }
                
            }  

        }
        
    }
};
