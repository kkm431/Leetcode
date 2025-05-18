class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ctr;
        int n= nums.size();
        for(auto i: nums){
            ctr[i]++;
        }
        
        for(auto i: nums){
            if(ctr[i] > n/2){
                return i;
            }
        }
        return 0;
    }
};