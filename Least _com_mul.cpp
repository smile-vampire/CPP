//题目描述
//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

//解题思路：
//最小公倍数 = 两数之积除以最大公约数，这里使用碾转相除法进行最大公约数的求解：即a与b的最大公约数
//可以转化为a、b之间的余数为两者之间最小的数之间的公约数。所以对于输入的两个数进行连续求余，直到
//余数为0，求余的分母即为结果。


#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r;
	while (r = a % b) {
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}