
#include<vector>
#include<iostream>
#include <map>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>>v(grid.size(),vector<bool>(grid[0].size(),false));
        int rows = grid.size();
        int cols = grid[0].size();
        map<string,bool>m;
        string path =".";
        for (int i =0; i < rows; i++)
        {
            for (int j =0 ; j < cols; j++)
            {
                if (!v[i][j] && grid[i][j]==1)
                {
                    dfs(grid,i,j,rows,cols,path,v);
                    m[path]=true;
                    cout << path<<endl;
                   cout <<"*************************************" <<endl;
                    
                    path.clear();
                   
                    path =".";

                }
            }
        }
        return m.size();
        
    }
    
    void dfs(vector<vector<int>>&g, int i, int j,int rows, int cols,string &path,vector<vector<bool>>&v)
    {
        v[i][j]=true;
       
        
        if (i+1 < rows && !v[i+1][j] && g[i+1][j]==1)
        {
            path+='d';
            dfs(g,i+1,j,rows,cols,path,v);
        }
        if (i-1 >=0 && !v[i-1][j] && g[i-1][j]==1)
        {
            path +='u';
            dfs(g,i-1,j,rows,cols,path,v);
        }
        if (j+1 <cols && !v[i][j+1] && g[i][j+1]==1)
        {
            path+='f';
            dfs(g,i,j+1,rows,cols,path,v);
        }
        if (j-1>=0 && !v[i][j-1] && g[i][j-1]==1)
        {
            path += 'b';
            dfs(g,i,j-1,rows,cols,path,v);

        }
        path+='p';
        
    }
        
};

int main ()
{
    Solution s; 

    vector<vector<int>>grid ={{0,0,0,0,1,1,1},
                              {1,1,1,1,1,1,1},
                              {0,0,0,0,0,0,0},
                              {0,0,0,0,1,1,1},
                              {1,1,1,1,1,1,0},
                              {0,0,0,1,0,0,0}};

    cout << s.numDistinctIslands(grid)<< endl;;
}