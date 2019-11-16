class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
         if (matrix.empty()) return 0;
         
        int rows = matrix.size();
        int cols = matrix[0].size();
        int mx =0;
        if (rows ==1 && cols ==1 ) return matrix[0][0]-'0'; 
       
        
        for( int i =0 ; i < rows; i++ ){
            for(int j =0; j < cols; j++){
                if(matrix[i][j]=='1' ){
               
                    if ( i !=0 && j !=0) {
                      matrix[i][j] = 1 + m(matrix[i-1][j],m(matrix[i][j-1],matrix[i-1][j-1]));   
                    }
                   
                    
                    mx = cmp(mx,matrix[i][j]-'0');
                    
                }
            }
        }
        
               return mx*mx;
        
    }
    
    int cmp(int a , int b){
        if(a>b)return a;
        return b;
    }
      int m(int a , int b){
        if(a>b)return b;
        return a;
    }
};