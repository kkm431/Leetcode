class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //by default on 1st element of intervals
        sort(intervals.begin(), intervals.end());


        vector<vector<int>> ans;

        for(int i=0; i < intervals.size(); i++){

            int start= intervals[i][0];
            int end= intervals[i][1];

            if(ans.empty() || ans.back()[1] < start){
                ans.push_back({start, end});
            }
            else{
                ans.back()[1] = max(ans.back()[1], end);
            }
        }

        return ans;
    }
};