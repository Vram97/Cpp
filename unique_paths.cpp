class Solution {
public:
    int uniquePaths(int m, int n) {
        // int x=0;
        // if(m==n){
        //     x=1;
        // }
        return round(tgamma(m+n-1)/(tgamma(m)*tgamma(n)));
    }
//     int uniquePaths(int m, int n) {
// 		int N = n+m-2,R = min(n-1,m-1);
// 		double result = 1;
// 		for(int i = 0; i < min(n-1,m-1); i++){
// 				result = result * N-- / R--;
//         }
// 		return round(result);
//    }
};
