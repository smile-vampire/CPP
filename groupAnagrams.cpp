//��дһ�ַ��������ַ�������������򣬽����б�λ�������һ�𡣱�λ����ָ��ĸ��ͬ�������в�ͬ���ַ�����
//
//ʾ�� :
//����: ["eat", "tea", "tan", "ate", "nat", "bat"] ,
//��� :
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
            //��λ�����������ͬ����Ϊkey
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
