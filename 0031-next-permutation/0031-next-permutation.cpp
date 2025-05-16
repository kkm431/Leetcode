class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int i = n-2;

        //Find pivot = nums[i] < nums[i+1] ? nums[i] 
        while(i >=0 && nums[i] >= nums[i + 1]){
            i--;
        }

        //Find idx from right which is first greater then pivot from right 
        if (i >= 0) {
            int j = n-1;
            while(j >=0 && nums[i] >= nums[j]){
                j--;
            }

            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};