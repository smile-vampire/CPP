//��Ŀ����
//С�׾���������������Ϸ.��һ��, ������һ�������������Ϸ, ���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����, 
//��������������n������, ÿ������ķ�����Ϊb1, b2, b3...bn.��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,
//��ô���������ɴ�ܹ���, �� ��ʹ���Լ�������ֵ����bi; ���bi����c, ����Ҳ�ܴ�ܹ���, ����������ֵֻ������bi 
//��c�����Լ��.��ô��������, ��һϵ�еĶ�����, С�׵���������ֵΪ���� ?

//����˼·��
//һ����ֱ�����bi, һ�����ۼӵ�ǰ����ֵ��bi�����Լ�������Լ��
//����ͨ����ת�������ã�a��b�����Լ���൱��b��a, b���������Լ�������������Ϊ0�� ��bΪ��
//����

#include<vector>
#include<iostream>
using namespace std;
int GCD(int a, int b)
{
	int c;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	int n, power;
	vector<int> num;
	while (cin >> n >> power)
	{
		num.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		for (int k = 0; k < n; k++)
		{
			if (num[k] < power)
			{
				power += num[k];
			}
			else
			{
				power += GCD(power, num[k]);
			}
		}
		cout << power << endl;
	}
	return 0;
}