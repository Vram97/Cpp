class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int path=triangle[0][0];
        vector<int>::iterator it=triangle[0].begin();
        vector<int>::iterator it_end;

        for(int i=1;i<triangle.size();i++){
            it=triangle[i].begin()+(it-triangle[i-1].begin());
            if(distance(it,triangle[i].end())<2){
                it_end=triangle[i].end();
            }
            else{

                it_end=it+2;

            }
            // cout<<*it_end<<endl;

            it=min_element(it,it_end);

            path+=*it;

        }
        auto val=min_element(it,triangle[triangle.size()-1].end());
        if(*val<*it){
            path+=*val;
        }

        return path;
    }
};
