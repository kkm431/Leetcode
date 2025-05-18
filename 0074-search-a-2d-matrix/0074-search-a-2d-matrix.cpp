class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int start, int end, int target, int row){
        while(start <= end){
            int mid = start + (end - start)/2;

            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int ro=matrix.size();
        int co=matrix[0].size();
        int low = 0;

        for(int i=0; i< ro; i++){
            if(matrix[i][0] <= target && target <= matrix[i][co-1]){
                return binarySearch(matrix, 0, co-1, target, i);
            }
        }

        return false;
    }
    
};