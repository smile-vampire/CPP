//题目描述
//在命令行输入如下命令：
//xcopy / s c : \ d : \，
//各个参数如下：
//
//参数1：命令字xcopy
//参数2：字符串 / s
//参数3：字符串c : \
//参数4 : 字符串d : \
//请编写一个参数解析程序，实现将命令行各个参数解析出来。
//
//解析规则：
//1.参数分隔符为空格
//2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s 
//“C : \program files” “d : \”时，参数仍然是4个，第3个参数应该是字符串C : \program files，
//而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//3.参数不定长
//4.输入由用例保证，不会出现不符合要求的输入

//解题思路：
//通过以空格和双引号为间隔，统计参数个数。对于双引号，通过添加flag，保证双引号中的
//空格被输出。

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		string s;//临时字符串
		vector<string> v;
		bool falg = false;//标识是否为""
		for (int i = 0; i < str.size(); i++)
		{
			if (falg)//引号
			{
				if (str[i] != '"')
				{
					s += str[i];
				}
				else
					falg = false;
			}
			else
			{
				if (str[i] == ' ')
				{
					//说明字符串一个遍历完成
					v.push_back(s);
					s = "";
				}
				else if (str[i] == '"')
				{
					falg = true;
				}
				else
				{
					s += str[i];
				}
			}
		}
		v.push_back(s);
		cout << v.size() << endl;
		for (auto& e : v)
			cout << e << endl;
	}
	return 0;
}