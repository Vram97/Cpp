class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int len=nums.size();
        vector<bool>v(len,false);
        v[0]=true;

        for(int i=0;i<len;i++){
        // std::cout<<"Start: "<<i<<std::endl;
            if(v[i]==true){
                if(nums[i]>=len-1){
                    return true;
                }
                for(int j=nums[i];j>0;j--){
                    int temp=j+i;
                    // std::cout<<"Temp: "<<temp<<std::endl;

                    if(temp>=len-1){
                        return true;
                    }
                    else{
                        v[temp]=true;
                    }
                }
            }
        }
        return v[len-1];

    }
};
