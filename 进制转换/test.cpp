//题目描述
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

//解题思路：N进制数，每个进制位的值分别是X0* N 0，X1\ * N 1, X2* N ^ 2.....，X0，
//X1，X2就是这些进制位的值，就是就是进行取模余数就是当前低进制的位的值是多少，通过除掉进制数，进
//入下一个进制位的计算。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    //如果是负数先要转换
    bool falg = false;
    string s;
    string num = "0123456789ABCDEF";
    if (M < 0)
    {
        M = 0 - M;
        falg = true;
    }
    // 按进制换算成对应的字符添加到s
    while (M > 0)
    {
        s += num[M % N];
        M /= N;
    }

    if (falg)
    {
        s += '-';
    }
    //反转后的结果才是最终结果
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}