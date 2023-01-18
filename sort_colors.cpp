class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int count=0;

        while(count<nums.size()){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.insert(nums.begin(),0);
                i++;
            }
            else if(nums[i]==2){
                nums.erase(nums.begin()+i);
                nums.push_back(2);
                
            }
            else{
                i++;
            }
            count++;
        }
        
    }
};
