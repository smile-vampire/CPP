//��Ŀ����
//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������

//����˼·��N��������ÿ������λ��ֵ�ֱ���X0* N 0��X1\ * N 1, X2* N ^ 2.....��X0��
//X1��X2������Щ����λ��ֵ�����Ǿ��ǽ���ȡģ�������ǵ�ǰ�ͽ��Ƶ�λ��ֵ�Ƕ��٣�ͨ����������������
//����һ������λ�ļ��㡣

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    //����Ǹ�����Ҫת��
    bool falg = false;
    string s;
    string num = "0123456789ABCDEF";
    if (M < 0)
    {
        M = 0 - M;
        falg = true;
    }
    // �����ƻ���ɶ�Ӧ���ַ���ӵ�s
    while (M > 0)
    {
        s += num[M % N];
        M /= N;
    }

    if (falg)
    {
        s += '-';
    }
    //��ת��Ľ���������ս��
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}