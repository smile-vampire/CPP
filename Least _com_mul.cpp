//��Ŀ����
//������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������

//����˼·��
//��С������ = ����֮���������Լ��������ʹ����ת������������Լ������⣺��a��b�����Լ��
//����ת��Ϊa��b֮�������Ϊ����֮����С����֮��Ĺ�Լ�������Զ�������������������������ֱ࣬��
//����Ϊ0������ķ�ĸ��Ϊ�����


#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r;
	while (r = a % b) {
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}