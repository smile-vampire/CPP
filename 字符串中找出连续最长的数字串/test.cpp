//读入一个字符串str，输出字符串str中的连续最长的数字串
//输入：abcd12345ed125ss123456789
//输出：123456789

//解题思路：遍历字符串，使用cur去记录连续的数字串，如果遇到不是数字字符，则表示一个连续的数字串结束了，则将
//数字串跟之前的数字串比较，如果更长，则更新更长的数字串更新到res。

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, cur, res;
	cin >> str;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	cout << res << endl;
	return 0;
}