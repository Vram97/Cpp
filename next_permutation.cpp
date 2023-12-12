class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        const int sz=nums.size();
        int i=sz-2;

        int min_val=nums[sz-1];
        int min_idx=sz-1;
        bool bl=false;
        int prev_id=sz-1;

        while(i>-1){
            if(nums[i]<nums[prev_id]){
                if(nums[min_idx]>nums[i]){
                    swap(nums[i],nums[min_idx]);

                }
                else{
                    for(int j=sz-2;j>i;j--){
                        if(nums[j]>nums[i]){
                            swap(nums[i],nums[j]);
                            break;
                        }

                    }
                    // cout<<nums[i]<<endl;
                    // cout<<prev<<endl;
                }
                bl=true;
                break;
            }
            prev_id=i;
            i--;
        }

        if(bl==false){
            sort(nums.begin(),nums.end());
        }
        else{
            sort(nums.begin()+i+1,nums.end());
        }

    }
};
