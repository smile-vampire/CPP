//��Ŀ����
//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ�������
//��ÿ���µ���������Ϊ���٣�

//����˼·��
//��n���µ�������������������ɣ�һ�������ϸ��µ�����f(n - 1)����һ��������3���´�����ӣ�
//����һֻ����f(n - 2)�����Ե�n�������������� f(n) = f(n - 1) + f(n - 2)���������ڱ��࿼��쳲���
//�����С�

#include <iostream>
using namespace std;
int main() {
	int month;
	while (cin >> month) {
		int first = 1;
		int second = 1;
		int result;
		for (int i = 3; i <= month; ++i) {
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	}
	return 0;
}