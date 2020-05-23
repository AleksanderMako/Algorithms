
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.size()<1 )return vector<string>();
        vector<string>map ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        result.push_back("");

        for (int i =0 ; i < digits.size(); i++)
        {
            auto digit = digits[i]-'0';

            auto mapping = map[digit];

            if(mapping.size() < 1 )continue;
            
            vector<string>temp;
            for (int k =0 ;k < mapping.size(); ++k)
            {
                for (int j =0 ; j < result.size();++j)
                {
                    temp.push_back(result[j]+mapping[k]);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};

int main ()
{
    Solution s;
    auto test ="23";

   for(auto str : s.letterCombinations(test)) cout << str +" ";
}