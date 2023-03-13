class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0];
        int count=1;
        int cnt=1;
        int sz=nums.size();

    //     for(int i=0;i<sz;i++){
    //         if(prev==nums[i]){
    //             count++;
    //             if(count>2){
    //                 nums.erase(nums.begin()+i);
    //                 sz--;
    //             }
    //         }
    //         else{
    //             prev=nums[i];
    //             count=1;
    //         }
    //     }

    //     return sz;
    // }

        while(count<=sz-1){
            if(prev==nums[count]){
                cnt++;
                // cout<<cnt<<endl;
                if(cnt>2){
                    nums.erase(nums.begin()+count);
                    // cout<<"cut"<<endl;
                    sz--;
                }
                else{
                    count++;
                }
            }
            else{
                prev=nums[count];
                cnt=1;
                count++;
            }

        }
        return sz;
    }
};
