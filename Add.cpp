//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�� + �� - �� * �� / ����������š�

//����˼·�����ֵ���ӿ���ת��Ϊ�����Ƶļӷ���ע��ÿһλ������λ����
//1. ����������൱��ÿһλ��ӣ��������ǽ�λ��
#include <iostream>
using namespace std;
class Solution {
public:
	int Add(int num1, int num2) {
		while (num2 != 0) {
			int sum = num1 ^ num2; //�õ���Ӻ󲻰�����λ������
			int carray = (num1 & num2) << 1; //�õ�������ӵĽ�λ
			num1 = sum; //���������ӣ�ֱ����λΪ0
			num2 = carray;
		}
		return num1;
	}
};

int main()
{
	Solution s;
	int num1, num2;
	while (cin >> num1 >> num2)
	{
		s.Add(num1, num2);
	}
	return 0;
}