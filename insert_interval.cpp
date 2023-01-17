class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end(),[&](vector<int> a,vector<int> b){return a[0]<b[0];});

        for(int i=0;i<intervals.size();i++){
            if(i==0){
                ans.push_back(intervals[i]);
            }
            else{
                if((intervals[i][0]<=ans.back()[1]) && (intervals[i][1]>ans.back()[1])){
                    vector<int> v;
                    v.push_back(ans.back()[0]);
                    v.push_back(intervals[i][1]);
                    ans.pop_back();
                    ans.push_back(v);

                }
                else if(intervals[i][0] >ans.back()[1]){
                    ans.push_back(intervals[i]);
                }
                else{
                    ;
                }
            }
        }
        return ans;
    }
};
