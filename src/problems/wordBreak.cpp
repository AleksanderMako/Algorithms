#include<iostream>
#include<vector>
#include  <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if (s.size() < 1 ) return false;
        if (wordDict.size() < 1 )return false;
        unordered_set<string> m;
        vector<bool>dp(s.size()+1,false);
        for( string w : wordDict)m.insert(w);

        dp[0]=true;
        for (int i =1 ; i<s.size();i++)
        {
            for (int j = i-1; j  >=0; j--)
            {
                if(dp[j])
                {
                    string w = s.substr(j,i-j);

                    auto it = m.find(w);
                    if (it != m.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
};