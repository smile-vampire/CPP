//��Ŀ����
//�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ���������
//���������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
//����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
//��û�н���������һ�룬����0��

//����˼·
//��һ������˼·�����һ�������ִ�������һ���ˣ�������󣬱�Ȼ�����м䣬��������
//��������鿴�Ƿ���ϼ��ɡ��ڶ���˼·������mapͳ��ÿ�����ֳ��ֵĴ���������ж���û�г���һ���
//���֡�

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		//����һ���������֮���Ȼ�����м�
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//ͳ�������м�����ĸ���
			if (gifts[i] == middle)
			{
				count++;
			}
		}
		//�����������һ�룬����ڳ���һ�����
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};
/*˼·����mapͳ��*/
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		map<int, int> count;
		int middle = gifts.size() / 2;
		for (const auto& e : gifts)
		{
			++count[e];
		}
		for (const auto& e : count)
		{
			if (e.second >= middle)
				return e.first;
		}
		return 0;
	}
};

int main()
{
	Gift g;
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	g.getValue(v, n);
	return 0;
}