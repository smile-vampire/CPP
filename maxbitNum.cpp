//��Ŀ����
//���� : ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//���� : һ��byte�͵�����
//��� : ��
//���� : ��Ӧ�Ķ�����������1�����������

//����˼·��
//����λ���㣬��ȡÿһλ�Ķ�����ֵ����ȡ��iλ��ֵ��(n >> i) & 1�����1������������ۼӣ��������
//�������0��ʼ������

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n����32�ξͱ�Ϊ0
		while (n)
		{
			//��ȡ��ǰλ�Ķ�����ֵ
			if (n & 1)
			{
				//���1��ֵ�����������ۼӣ����Ҹ���������
				++count;
				maxCount = max(count, maxCount);
			}
			else
			{
				//���1��ֵ�������������ۼ�
				count = 0;
			}
			//����һ�Σ�Ϊ��ȡ��һλ������ֵ��׼��
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}