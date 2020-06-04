//���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
//��Դ��ţ����
//
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�
//ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������,
//ţţ��֪�������ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2

//����˼·��
//a[i + 1] > a[i] �������ǵ��������жϣ�ֱ����������һ��ֵ�����ڵ���Ϊֹcount++��Ȼ�������һλ�õ��ж�
//a[i + 1] < a[i]�������ǵ��������жϣ�ֱ����������һ��ֵ��С�ڵ���Ϊֹcount++��Ȼ�������һλ�õ��ж�
//a[i + 1] == a[i]�����в�����++i������һλ�ñ�������Ϊ��ȼȿ������ڷǵ������У�Ҳ�������ڷǵݼ�����

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    int count = 0;
    while (i < n)
    {
        if (a[i] < a[i + 1])
        {
            while (i < n && a[i] <= a[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
        else if (a[i] == a[i + 1])
        {
            i++;
        }
        else {
            while (i < n && a[i] >= a[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
    }
    cout << count << endl;
    return 0;
}