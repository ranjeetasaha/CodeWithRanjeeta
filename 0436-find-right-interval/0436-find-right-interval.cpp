class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>> startArr;

        for(int i=0; i<n; i++){
            startArr.push_back({intervals[i][0],i});
        }

        vector<int> ans(n);
        sort(startArr.begin(),startArr.end());

        for(int i=0; i<n; i++){
            int end = intervals[i][1];

            auto it = lower_bound(
                startArr.begin(),
                startArr.end(),
                make_pair(end,-1)
            );

            if(it==startArr.end()){
                ans[i] = -1;
            }            
            else{
                ans[i] = it->second;
            }
        }
        return ans;
    }
};