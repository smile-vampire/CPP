//��Ŀ����
//���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���

//����˼·��
//������Ҫ�ö�̬�滮��⣬MCS[i][j]��¼���ַ��� s1 ǰ i ���ַ��ͳ��ַ��� s2 ǰ j ���ַ�����Ӵ��ĳ�
//�ȣ���ʼ������ֵΪ 0���� s1[i - 1] = s2[j - 1]ʱ��MCS[i][j] = MCS[i - 1][j - 1] + 1������ʹ��һ�������ֵ
//start ����¼��Ӵ��ڶ��ַ��� s1 �г��ֵ���ʼλ�ã�maxlen��¼��ǰ��Ӵ��ĳ��ȣ���MCS[i][j] >
//maxlen ʱ��maxlen = MCS[i][j]�� ��start = i - maxlen ����s1[i - 1] != s2[j - 1]ʱ����Ҫ�κβ���������ȡ
//substr(start, maxlen)��Ϊ����


#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//����̵��ַ�����Ϊs1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				//����и����Ĺ����Ӵ������³���
				if (MCS[i][j] > max)
				{
					max = MCS[i][j];
						//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max
						start = i - max;
				}
			}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}