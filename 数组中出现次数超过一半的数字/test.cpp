//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }����������2�������г�����5�Σ�
//�������鳤�ȵ�һ�룬������2����������������0��


//����˼·������з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ�ڱ�������ʱ��������ֵ��
//һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ���������1�����������
//1��������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж���
//�Ƿ�����������ɡ�

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;
		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = numbers[0];
		int count = 1;


		for (int i = 0; i < numbers.size(); i++)
		{
			if (count == 0)
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
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