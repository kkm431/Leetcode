class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int cand = nums[0];

        for(int num: nums){
            if(cnt == 0){
                cand = num;
            }

            cnt += (cand == num)? 1 : -1;
        }
        return cand;
    }
};