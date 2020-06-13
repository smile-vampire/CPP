//��Ŀ����
//���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
//һ�����볤�� :
//5 �� : С�ڵ���4 ���ַ�
//10 �� : 5 ��7 �ַ�
//25 �� : ���ڵ���8 ���ַ�
//������ĸ :
//0 �� : û����ĸ
//10 �� : ȫ����С����д��ĸ
//20 �� : ��Сд�����ĸ
//�������� :
//0 �� : û������
//10 �� : 1 ������
//20 �� : ����1 ������
//�ġ����� :
//0 �� : û�з���
//10 �� : 1 ������
//25 �� : ����1 ������
//�塢���� :
//2 �� : ��ĸ������
//3 �� : ��ĸ�����ֺͷ���
//5 �� : ��Сд��ĸ�����ֺͷ���
//�������ֱ�׼ :
//>= 90 : �ǳ���ȫ
//>= 80 : ��ȫ��Secure��
//>= 70 : �ǳ�ǿ
//>= 60 : ǿ��Strong��
//>= 50 : һ�㣨Average��
//>= 25 : ����Weak��
//>= 0 : �ǳ���
//��Ӧ���Ϊ��
//VERY_SECURE
//SECURE,
//VERY_STRONG,
//STRONG,
//AVERAGE,
//WEAK,
//VERY_WEAK,
//���������������ַ��������а�ȫ������


#include<iostream>
#include<string>
using namespace std;
int numChar(string str, int k)
{
    //����ASCII���ж���ĸ��Сд
    int small = 0;
    int big = 0;
    for (int i = 0; i < k; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            big++;
        else if (str[i] >= 97 && str[i] <= 122)
            small++;
    }
    if ((small + big) == 0)
        return 0;
    else if (small == k || big == k)
        return 10;
    else if (small > 0 && big > 0)
        return 20;
    return 0;
}
int numNumber(string str, int k)
{
    //����ASCII���ж����ָ�������ȥ�ַ���0��֮����0~9֮��ļ�Ϊ����
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
            num++;
    }
    if (num == 0)
        return 0;
    else if (num == 1)
        return 10;
    else
        return 20;
}
int numSymbal(string str, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        //��ȥ��ĸ�����֣�������Ϊ����
        if (!(str[i] >= 65 && str[i] <= 90)
            && !(str[i] >= 97 && str[i] <= 122)
            && !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
            num++;
    }
    if (num == 0)
        return 0;
    else if (num == 1)
        return 10;
    else
        return 25;
}
int main()
{
    string str;
    while (cin >> str)
    {
        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
        int k = str.size();
        if (k <= 4)
            sum1 = 5;
        else if (k >= 8)
            sum1 = 25;
        else
            sum1 = 10;
        sum2 = numChar(str, k);
        sum3 = numNumber(str, k);
        sum4 = numSymbal(str, k);
        if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
        {
            if (sum2 == 10)
                sum5 = 3;
            else
                sum5 = 5;
        }
        else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
            sum5 = 2;
        if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
            cout << "VERY_SECURE" << endl;
        else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
            cout << "SECURE" << endl;
        else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
            cout << "VERY_STRONG" << endl;
        else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
            cout << "STRONG" << endl;
        else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
            cout << "AVERAGE" << endl;
        else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
            cout << "WEAK" << endl;
        else
            cout << "VERY_WEAK" << endl;
    }
    return 0;
}