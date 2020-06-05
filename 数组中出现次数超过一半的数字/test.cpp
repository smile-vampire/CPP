//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。由于数字2在数组中出现了5次，
//超过数组长度的一半，因此输出2。如果不存在则输出0。


//解题思路：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历数组时保存两个值：
//一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减
//1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它
//是否符合条件即可。

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;
		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = numbers[0];
		int count = 1;


		for (int i = 0; i < numbers.size(); i++)
		{
			if (count == 0)
				// 更新result的值为当前元素，并置次数为1
				result = numbers[i];
			else if (numbers[i] == result)
				count++;
			else
				count--;
		}

		count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == result)
				count++;
		}

		return (count > numbers.size() / 2) ? result : 0;
	}
};

int main()
{
	Solution s;
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(2);

	cout << s.MoreThanHalfNum_Solution(numbers);
	return 0;
}