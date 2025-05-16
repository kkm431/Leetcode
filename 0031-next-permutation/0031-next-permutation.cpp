class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the pivot - the first element from the end that breaks the descending order
        // We start from the second last element (n-2) and compare with its next element
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // Step 2: If we found a pivot (i >= 0), find the smallest element to the right of pivot that's larger than it
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            // Swap the pivot with this larger element
            swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse the elements after the pivot to get the smallest possible permutation
        // This works because the elements after pivot were in descending order, 
        // and reversing makes them ascending (the smallest possible arrangement)
        reverse(nums.begin() + i + 1, nums.end());
        
        // The array is now modified to the next permutation in place
    }
};