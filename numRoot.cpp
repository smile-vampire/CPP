
//数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数
//或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
//比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
//再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，
//因此3 是39 的数根。
//现在给你一个正整数，输出它的数根。

//解题思路：
//1. 接收字符串得到各个数字，并且每位求和（为了得到的数字不大于99）
//2. 循环对大于9的数字进行对10取余和整除操作，将两个结果进行相加得到树根

#include <iostream>
#include <string>
using namespace std;
int numRoot(int num) {
	int nroot = 0;
	while (num > 0) {
		/*每次只获取个位数字---个位数+十位数*/
		nroot += num % 10;
		num /= 10;
	}
	while (nroot > 9) {
		nroot = numRoot(nroot);
	}
	return nroot;
}
int main()
{
	std::string origin;
	while (std::cin >> origin) {
		int sum = 0;
		//先将每一位进行相加得到总和，防止数字过大
		for (int i = 0; i < origin.length(); i++) {
			sum += origin[i] - '0';
		}
		//对总和求树根
		std::cout << numRoot(sum) << std::endl;
	}
	return 0;
}