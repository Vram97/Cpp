class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // sort(nums1.begin(),nums1.end());
        int len1=nums1.size();
        const int len2=nums2.size();

        if(len1==0){
            len1=len2;
            nums1=nums2;
            nums2.clear();
            const int len2=0;
        }

        int start=0;
        int end=len1;

        int idx=-1;
        int prev=-1;

        for(int i=0;i<len2;i++){
            while(true){
                prev=idx;
                idx=(start+end)/2;

                if(prev==idx){
                    if(idx==len1-2 && nums2[i]>nums1[len1-1]){
                        nums1.emplace_back(nums2[i]);
                        start=len1;
                    }
                    else if(idx==0 && nums2[i]<nums1[0]){
                        nums1.insert(nums1.begin(),nums2[i]);
                        start=0;
                    }
                    else{
                        nums1.insert(nums1.begin()+idx+1,nums2[i]);
                        start=idx+1;
                        
                    }

                    // cout<<nums2[i]<<endl;

                    // start=idx;
                    end=len1++;
                    idx=-1;
                    // cout<<"........."<<endl;
                    break;

                }
                else if(nums1[idx]>nums2[i]){
                    end=idx;
                }
                else{
                    start=idx;
                }
            }
            // cout<<"Breaking"<<endl;
        }
        // cout<<"For done"<<endl;
        // cout<<nums1[1]<<endl;
        // cout<<nums1[2]<<endl;
        // cout<<len1<<endl;
        // cout<<(nums1[len1/2]+nums1[(len1/2)-1])/2<<endl;
        int ll=len1/2;
        return((len1)%2==0)?(float)(nums1[ll]+nums1[ll-1])/2:nums1[ll];

    }
};
