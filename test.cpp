//��Ŀ����
//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
//����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1��
//���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����

//����˼·��
//�������ͨ�����ҵ�����N���������Fibonacci�������������ֱ�ȡ�Ծ���N����������һ����L���ұ�һ
//����R��Ȼ��ͨ��min(N - L, R - N)�ҵ���С������

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		//�ҵ���NС�Ҿ���N����������������
		if (f < N)
			l = N - f;
		else
		{
			//�ҵ���N���Ҿ���N����������������
			r = f - N;
			break;
		}
	}
	//ȡ��С����
	cout << min(l, r) << endl;
	return 0;
}