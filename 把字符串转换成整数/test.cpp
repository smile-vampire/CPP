//题目描述
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

//【解题思路】：
//解题思路非常简单，就是上次计算的结果 * 10，相当于10进制进位，然后加当前位的值。
//例如：“123”转换的结果是
//sum = 0
//sum * 10 + 1->1
//sum * 10 + 2->12
//sum * 10 + 3->123
//本题的关键是要处理几个关键边界条件：
//1. 空字符串
//2. 正负号处理
//3. 数字串中存在非法字符

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-') //处理负号
		{
			symbol = -1;
			str[0] = '0'; //这里是字符'0',不是0
		}
		else if (str[0] == '+') //处理正号
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol * sum;
	}
};

int main()
{
	string str;
	getline(cin, str);
	Solution s;
	cout << s.StrToInt(str) << endl;
	return 0;
}