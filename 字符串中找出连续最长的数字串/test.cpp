//����һ���ַ���str������ַ���str�е�����������ִ�
//���룺abcd12345ed125ss123456789
//�����123456789

//����˼·�������ַ�����ʹ��curȥ��¼���������ִ�������������������ַ������ʾһ�����������ִ������ˣ���
//���ִ���֮ǰ�����ִ��Ƚϣ��������������¸��������ִ����µ�res��

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, cur, res;
	cin >> str;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	cout << res << endl;
	return 0;
}