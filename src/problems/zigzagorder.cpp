#include<iostream>
#include <vector>
#include<map>
using namespace std;

class Solution {
public:
map<int,bool>visited;
    string convert(string s, int numRows) {
        vector<vector<char>>rows (numRows);
        
        int row =0 ;
        int step =1;
        string result ="";

        for (int i =0 ; i < s.size();i++)
        {
            if (row ==0 )step =1; 
            if ( row == numRows-1)step =-1;
            rows[row].push_back(s[i]);
            row=row+step;
            cout <<endl;
        }

        for (auto v : rows){
            for (auto c : v)
            {

                result+=c;
            }
            cout << endl;
        }
        return result;

    }

};

int main(){

    Solution s; 
    string test = "PAYPALISHIRING";
    string result = s.convert(test,3);
    
    cout<< result<< endl;
    string expected ="PAHNAPLSIIGYIR";

    cout << result.compare(expected)<<endl;
}

/*
p               a               h               n
    a       p       l       s       i       i       g
        y               i               r
*/
//PAHNAPLSIIGYIR
//pahnaplsiigyir