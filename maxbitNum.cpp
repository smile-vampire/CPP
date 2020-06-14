//题目描述
//功能 : 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//输入 : 一个byte型的数字
//输出 : 无
//返回 : 对应的二进制数字中1的最大连续数

//解题思路：
//根据位运算，获取每一位的二进制值。获取第i位的值：(n >> i) & 1。如果1连续，则计数累加，如果不连
//续，则从0开始计数。

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n右移32次就变为0
		while (n)
		{
			//获取当前位的二进制值
			if (n & 1)
			{
				//如果1的值连续，计数累加，并且跟新最大计数
				++count;
				maxCount = max(count, maxCount);
			}
			else
			{
				//如果1的值不连续，重新累加
				count = 0;
			}
			//右移一次，为获取下一位二进制值做准备
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}