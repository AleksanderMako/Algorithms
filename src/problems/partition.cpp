
#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        unordered_map<char,int>m;
        vector<int>partitions;
        for (int i =0 ; i < S.size(); i++)
        {
            m[S[i]]=i;
        }
        
        int slow =0;
        int mxIndex=-1;
        
     for (int i = 0 ; i < S.size();i++)
     {
          mxIndex= max(m[S[i]],mxIndex);
         if (i == mxIndex)
         {
             partitions.push_back(i-slow);
             slow =i+1;
         }

     }
        return partitions;
    }
};

int main()
{
     string s  = "ababcbacadefegdehijhklij";
     Solution sol;

     for( auto x : sol.partitionLabels(s))cout << x << " ";
}