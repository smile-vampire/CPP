//��Ŀ����
//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
//����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬
//С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á�
//С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
//���磺
//N = 4��M = 24��
//4->6->8->12->18->24
//����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��

//����˼·����̬�滮������vector���飬v[i]��ʾ����i����С��������ʼ������INT_MAX,���v[M]==INT_MAX,��
//����������
//��ʼ״̬��v[N] = 0
//ת�Ʒ���v[i + j] = min(v[i] + 1, v[i + j])   //iΪʯ���ţ�jΪi��Լ��

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<int> v(M + 1, INT_MAX);
        v[N] = 0;
        for (int i = N; i <= M; i++)
        {
            if (v[i] == INT_MAX)
                continue;
            for (int j = 2; j < N; j++)
            {
                if (i % j == 0)
                {
                    if (i + j <= M)
                    {
                        v[i + j] = min(v[i] + 1, v[i + j]);
                    }
                    if (i + (i / j) <= M)
                    {
                        v[i + (i / j)] = min(v[i] + 1, v[i + (i / j)]);
                    }
                }
            }
        }
        if (v[M] == INT_MAX)
        {
            v[M] = -1;
        }
        cout << v[M] << endl;
    }
    return 0;
}