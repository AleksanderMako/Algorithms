

#include <iostream>
#include<vector>
#include<map>
#include <ctype.h>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        vector<string>words;
        map<string,int>f;
        map<string,bool>b;
        
        for (auto w:banned)b[w]=true;
        
        parse(words,paragraph);
        
        string m="";
        for(auto w:words)
        {
            f[w]++;
            //cout << w << " :" << f[w] <<endl;
        }
        for (auto it =f.begin();it !=f.end();it++)
        {
            m = it->second >= f[m] && b.find(it->first) == b.end()
            ? it->first
            :m;
        }
        return m;
        
        
    }    
    void parse(vector<string>&w,string paragraph)
    {
       // cout << "in parse now "<< endl;
        string word="";
        for (char c:paragraph)
        {
            if(isalpha(c))
            {
                c =tolower(c);
               
                word+=c;
            }
            else if (word.size()>=1)
            {
                w.push_back(word);
                //cout << word <<" ";
                word="";
            }
        }
        if (word.size() !=0) w.push_back(word);

        
    }
};

