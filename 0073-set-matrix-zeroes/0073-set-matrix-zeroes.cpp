class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<pair<int,int>> z;
        vector<int> p(matrix[0].size(),0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    z.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto j:z)
            {
                matrix[j.first]=p;
                matrix[i][j.second]=0;
            }
        }
        
    }
};