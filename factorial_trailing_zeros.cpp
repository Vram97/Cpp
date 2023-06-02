class Solution {
public:
    int trailingZeroes(int n) {
        // int x=n/5;
        int sum=0;
        while(n!=0){
            n/=5;
            sum+=n;
        }
        return sum;
    }
};
