class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        int temp;
        vector<int> ans;

        while(left!=right){
            temp=numbers[left] + numbers[right];

            if(temp>target){
                right--;
            }
            else if(temp<target){
                left++;
            }
            else{
                ans.emplace_back(left+1);
                ans.emplace_back(right+1);
                break;
            }
        }

        return ans;
        
    }
};
