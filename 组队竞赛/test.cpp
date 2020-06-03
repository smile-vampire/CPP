//链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
//来源：牛客网
//牛牛举办了一次编程比赛, 参加比赛的有3* n个选手, 每个选手都有一个水平值a_i.现在要将这些选手进行组队, 一共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如 :
//一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2
//为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。
//如样例所示 :
//如果牛牛把6个队员划分到两个队伍
//如果方案为 :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//而如果方案为 :
//	team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.
//	没有比总和为10更大的方案, 所以输出10.



//解题思路：贪心算法，每次得到局部最优解。不能选最大值要选第二大的值
//排序，然后取下标为3n - 2，3n - 4 ，3n - 4...n + 2，n位置的元素累加即可，相当下标为[0, n - 1]的n个数
//做每组的最左边的数，剩下的2个数据两个为一组，大的值做最右边的数，次大的做中间值，这里就是
//把这个次大的值加起来。
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr;
		arr.resize(3*n);
		for (int i = 0; i < arr.size(); i++)
		{
			cin >> arr[i];
		}
		//排序
		sort(arr.begin(), arr.end());
		int sum = 0;
		for (int i = n; i <= 3*n-2; i+=2)
		{
			sum += arr[i];
		}
		cout << sum << endl;
	}
	return 0;
}