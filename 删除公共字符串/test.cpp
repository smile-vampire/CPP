//题目描述
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”

//解题思路：
//1. 将第二个字符串的字符都映射到一个hashtable数组中，用来判断一个字符在这个字符串。
//2. 判断一个字符在第二个字符串，不要使用删除，这样效率太低，因为每次删除都伴随数据挪动。这里可
//以考虑使用将不在字符添加到一个新字符串，最后返回新新字符串。

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	// 使用哈希映射思想先str2统计字符出现的次数
	int hashtable[256] = { 0 };
	for (int i = 0; i < str2.size(); i++)
	{
		hashtable[str2[i]]++;
	}
	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
	// str2中没有出现过，则将他+=到ret。
	string ret;
	for (int i = 0; i < str1.size(); i++)
	{
		if (hashtable[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}