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
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char>>alphabet;
        map<char,bool>visited;
        map<char,bool>explored;
        if (words.size()<1)return "";
        for(string word : words)
        {
            for (char c : word)alphabet[c]= vector<char>();
        }
        
        string path="";
        for (int i =1 ; i < words.size();i++)
        {
            auto mismatchPair= mismatch(words[i-1].begin(),words[i-1].end(),
            words[i].begin(),words[i].end());

            if (mismatchPair.first != words[i-1].end() && mismatchPair.second == words[i].end())return "";
           if(mismatchPair.first != words[i-1].end())
           {
             alphabet[*mismatchPair.first].push_back(*mismatchPair.second);

           } else 
           {
               alphabet[words[i-1][0]]= vector<char>();
           }
            explored[*mismatchPair.first]=false;
        }
        
        for( auto it = alphabet.begin(); it != alphabet.end(); it++)
        {
            if (!explored[it->first])
            {
                if (!dfs(it->first,visited,alphabet,path,explored))return "";
            }
        }
        reverse(path.begin(),path.end());
        return path;
    }

    bool dfs(char c , map<char,bool>&v,unordered_map<char,vector<char>>&g,string & path,map<char,bool>&explored)
    {
        v[c]=true;

        for (int j =0 ; j < g[c].size();j++)
        {
            if (explored[g[c][j]])continue;
            if (v[g[c][j]] || !dfs(g[c][j],v,g,path,explored))return false;
            
        }
        path+=c;
        v[c]=false;
        explored[c]=true;
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> test = {"wrt","wrf","er","ett","rftt"};
    vector<string> test1 = {"x","y","x"};
    vector<string> test2 = {"x","x"};
    vector<string> test3={"abc","ab"};

    cout << s.alienOrder(test3) << endl;
    // s.alienOrder(test);
}