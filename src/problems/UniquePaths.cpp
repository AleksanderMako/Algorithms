class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1 ) return 0;
        if (rows ==0 || cols ==0 ) return 1;
        vector<vector<long long int>> dp(rows,vector<long long int>(cols,0));
        
       
        for (int r =0 ; r < rows; r++){
            for (int c =0 ;c < cols;c++){
           
                if(obstacleGrid[r][c]==1 )dp[r][c] =0;
                else {
                    if (c ==0 && r ==0 )dp[r][c] =1;
                   else  if (c ==0 ) dp[r][c] =dp[r-1][c];
                    else if (r ==0 )dp[r][c] = dp[r][c-1];
                    else dp[r][c] = dp[r-1][c]+dp[r][c-1];
                }
              
            }
        }
        
        return dp[rows-1][cols-1];
        
    }
};