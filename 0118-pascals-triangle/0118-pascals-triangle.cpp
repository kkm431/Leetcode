class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);

        for(int i=0; i<n; i++){
            res[i]= vector<int>(i+1);
            for(int j=0; j<=i; j++){
                if(i == j || j == 0){
                    res[i][j] = 1;
                }
                else{
                    res[i][j] = res[i-1][j] + res[i-1][j-1];
                }
            }
        }

        return res;
    }
};