class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int> gains;
        int profit=0;
        int temp;
        const int len= prices.size();

        if(len==0 || len==1){
            return 0;
        }

        for(int i=1;i<len;i++){
            temp=prices[i]-prices[i-1];
            if(temp > 0){
                profit+=temp;
            }
        }
        
        return profit;
    }
};
