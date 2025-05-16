class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize with first element to handle single-element arrays correctly
        int currSum = nums[0];
        int maxSum = nums[0];

        // Start from second element
        for(int i = 1; i < nums.size(); i++) {
            // Decide whether to add to current subarray or start new one
            currSum = max(nums[i], currSum + nums[i]);
            
            // Track the maximum sum we've seen so far
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};