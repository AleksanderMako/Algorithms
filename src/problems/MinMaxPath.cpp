
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;

class Solution1
{
    // Brute force
public:
    int maximumMinimumPath(vector<vector<int>> &A)
    {
        int min = __INT_MAX__;
        int gMin = -1;
        vector<vector<bool>> v(A.size(), vector<bool>(A[0].size(), false));
        int rows = A.size();
        int cols = A[0].size();
        v[0][0] = true;
        dfs(0, 0, v, A, rows, cols, A[0][0], gMin);
        return gMin;
    }

    void dfs(int i, int j, vector<vector<bool>> &v, vector<vector<int>> &m, int rows, int cols, int pathmin, int &globalPath)
    {
        if (i == rows - 1 && j == cols - 1)
        {
            pathmin = min(m[i][j], pathmin);
            globalPath = max(globalPath, pathmin);
            return;
        }
        v[i][j] = true;

        pathmin = min(m[i][j], pathmin);

        if (i + 1 < rows && !v[i + 1][j])
            dfs(i + 1, j, v, m, rows, cols, pathmin, globalPath);
        if (i - 1 >= 0 && !v[i - 1][j])
            dfs(i - 1, j, v, m, rows, cols, pathmin, globalPath);
        if (j + 1 < cols && !v[i][j + 1])
            dfs(i, j + 1, v, m, rows, cols, pathmin, globalPath);
        if (j - 1 >= 0 && !v[i][j - 1])
            dfs(i, j - 1, v, m, rows, cols, pathmin, globalPath);
        v[i][j] = false;
    }
};

typedef pair<int,int>ii;
typedef pair<int,ii>triple;
class Solution
{
    // Brute force
public:
    priority_queue<triple> q;
    int maximumMinimumPath(vector<vector<int>> &A)
    {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<bool>>v(rows,vector<bool>(cols,false));
        q.push(triple(A[0][0],ii(0,0)));
        v[0][0]=true;
        return bfs(v,A,rows,cols);
    }

    int bfs( vector<vector<bool>> &v, vector<vector<int>> &m, int rows, int cols)
    {
        int levelMax=__INT_MAX__;
        while (!q.empty())
        {
            int s = q.size();
            
            
                auto front = q.top();
                auto coordinates = front.second;
                auto val = front.first;
                auto x = coordinates.second;
                auto y = coordinates.first;
                q.pop();
                if (x == cols-1 && y == rows-1)break;
                levelMax  = min (levelMax,val);
                //cout << val<<endl;
                if (y + 1 < rows && !v[y + 1][x])
                    {q.push(triple(m[y+1][x],ii(y+1,x))); v[y+1][x]=true; }
                if (y - 1 >= 0 && !v[y - 1][x])
                   {q.push(triple(m[y-1][x],ii(y-1,x))); v[y-1][x]=true;}
                if (x + 1 < cols && !v[y][x + 1])
                    {q.push(triple(m[y][x+1],ii(y,x+1)));v[y][x+1]=true;}
                if (x - 1 >= 0 && !v[y][x - 1])
                    {q.push(triple(m[y][x-1],ii(y,x-1)));v[y][x-1]=true;}
            
           
        }
        return levelMax;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> test = {{3,3,2,0,2,2,3},{0,2,3,0,0,2,0},{3,0,2,1,1,1,1},{3,0,0,0,2,2,0},{2,2,3,0,2,2,3}};
    //{{5,4,5},{1,2,6},{7,4,6}};
    //{{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}};
    cout << s.maximumMinimumPath(test) << endl;
}