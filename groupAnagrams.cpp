//编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。
//
//示例 :
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"] ,
//输出 :
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //hash+sort
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for (auto& e : strs)
        {
            string tmp = e;
            sort(tmp.begin(), tmp.end());
            //变位词排序后结果相同，作为key
            hash[tmp].push_back(e);
        }

        for (auto& e : hash)
        {
            res.push_back(e.second);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    s.groupAnagrams(a);
    return 0;
}
