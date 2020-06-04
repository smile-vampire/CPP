//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I

//先将整个字符串逆置过来，再遍历字符串，找出每个单词，对单词逆置。这里我们使用了stl算法中的
//reverse，所以这里使用迭代器遍历string

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    //反转整体
    reverse(s.begin(), s.end());
    //局部反转
    auto start = s.begin();
    while (start != s.end())
    {
        auto end = start;
        while (end != s.end() && *end != ' ')
        {
            end++;
        }
        reverse(start, end);
        if (end != s.end())
        {
            start = end + 1;
        }
        else
        {
            start = end;
        }
    }
    cout << s << endl;
    return 0;
}