//链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
//来源：牛客网
//
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。
//牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列,
//牛牛想知道他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2

//解题思路：
//a[i + 1] > a[i] ，则进入非递增序列判断，直到遍历到下一个值不大于等于为止count++，然后进行下一位置的判断
//a[i + 1] < a[i]，则进入非递增序列判断，直到遍历到下一个值不小于等于为止count++，然后进行下一位置的判断
//a[i + 1] == a[i]不进行操作，++i进行下一位置遍历，因为相等既可以属于非递增序列，也可以属于非递减序列

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    int count = 0;
    while (i < n)
    {
        if (a[i] < a[i + 1])
        {
            while (i < n && a[i] <= a[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
        else if (a[i] == a[i + 1])
        {
            i++;
        }
        else {
            while (i < n && a[i] >= a[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
    }
    cout << count << endl;
    return 0;
}