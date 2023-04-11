class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v{-1,-1};
        int ul=nums.size();
        if(ul==0){
            return v;
        }
        int sz=ul;
        int ll=0;
        int curr=ul/2;
        int prev=-1;
        


        while(nums[curr]!=target){
            cout<<ll<<endl;
            cout<<ul<<endl;
            if(prev==curr){   
                return v;
            }
            if(target<nums[curr]){
                ul=curr;
            }

            else if(target>nums[curr]){
                ll=curr;

            }
            else{
                break;
            }
            prev=curr;
            curr=(ll+ul)/2;
            
        }

        int count_bk=1;
        bool bk=true;
        int count_fw=1;
        bool fw=true;

        while(bk==true || fw==true){
          if(curr+count_fw<sz){
            if(nums[curr+count_fw]==target){
                count_fw++;
            }
            else{
                fw=false;
            }
          }
          else{
              fw=false;
          }
          if(curr-count_bk>=0){
            if(nums[curr-count_bk]==target){
                count_bk++;
            }
            else{
                bk=false;
            }
          }
          else{
              bk=false;
          }

        }

        v={curr-count_bk+1,curr+count_fw-1};

        return v;

    }
};
