//��Ŀ����
//�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס�
//���ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�
//������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
//������ɫ����n(1��n��13), ͬʱ������������Ϊn������left, right, �ֱ����ÿ����ɫ���������׵�������
//���ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

//����˼·��
//���ڷ�0��������a1, a2...an��Ҫ������ȡֵ����ÿһ������
//n = sum(a1...an) - a1 + 1��Ҳ����������ȥ��Сֵ֮���һ��
//���Զ���������������ɫ�������������У���Ҫ����ÿһ����ɫ������С����leftsum = �������
//�� - �����Сֵ + 1�� rightsum = �ұ������� - �ұߵ���Сֵ + 1����������0���ڵģ�����Ҫ��
//�ۼӣ���֤����ÿһ����ɫ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		//����ÿһ����ɫ��������������
		for (int i = 0; i < n; i++) {
			//������0���ڵ���ɫ���ף��ۼ�
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			//���������ֶ��е���ɫ���ף�ִ���ۼ�-��Сֵ+1
			//�ҵ���Сֵ������
			else {
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		//���Ϊ�����Ҷ����������������еĽ��+��0���ڵ�������+����ټ�һ�϶����ܱ�֤��
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

int main()
{
	Gloves g;
	int n;
	cin >> n;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v2[i];
	}

	cout << g.findMinimum(n, v1, v2) << endl;
	return 0;
}