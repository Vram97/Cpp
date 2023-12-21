class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(newInterval.empty()){
            return intervals;
        }

        if(intervals.empty()){
            intervals.emplace_back(newInterval);
            return intervals;
        }

        int sz=intervals.size();
        int i=0;
        bool bl=false;

        while(i<sz){
            if(newInterval[0]>=intervals[i][0] && newInterval[0]<=intervals[i][1]){
                intervals[i][1]=max(intervals[i][1],newInterval[1]);

                int idx=i+1;

                // cout<<idx<<endl;
                // cout<<sz<<endl;

                while(idx<sz){
                    // cout<<"Inside"<<endl;
                    if(intervals[i][1]>=intervals[idx][0] && intervals[i][1]<=intervals[idx][1]){
                        intervals[i][1]=intervals[idx][1];
                        intervals.erase(intervals.begin()+idx);
                        // sz--;
                        break;
                    }
                    else{
                        if(intervals[i][1]>=intervals[idx][1] ){
                            intervals.erase(intervals.begin()+idx);
                            sz--;

                        }
                        else{
                            break;
                        }
                    }
                }
                bl=true;
                break;

            }
            else if(newInterval[0]<intervals[i][0]){
                // vector<int> temp  =newInterval;
                // int idx=i;

                while(i<sz){
                    // cout<<"Inside"<<endl;
                    if(newInterval[1]>=intervals[i][0] && newInterval[1]<=intervals[i][1]){
                        newInterval[1]=intervals[i][1];
                        intervals.erase(intervals.begin()+i);
                        // sz--;
                        break;
                    }
                    else{
                        if(newInterval[1]>=intervals[i][1] ){
                            intervals.erase(intervals.begin()+i);
                            sz--;

                        }
                        else{
                            break;
                        }
                    }
                }

                intervals.insert(intervals.begin()+i,newInterval);
                bl=true;
                break;

            }

            i++;
        }
        if(bl==false){
            intervals.emplace_back(newInterval);

        }
        return intervals;
        
    }
};
