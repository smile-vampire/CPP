//��Ŀ����
//�������������������
//xcopy / s c : \ d : \��
//�����������£�
//
//����1��������xcopy
//����2���ַ��� / s
//����3���ַ���c : \
//����4 : �ַ���d : \
//���дһ��������������ʵ�ֽ������и�����������������
//
//��������
//1.�����ָ���Ϊ�ո�
//2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy / s 
//��C : \program files�� ��d : \��ʱ��������Ȼ��4������3������Ӧ�����ַ���C : \program files��
//������C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
//3.����������
//4.������������֤��������ֲ�����Ҫ�������

//����˼·��
//ͨ���Կո��˫����Ϊ�����ͳ�Ʋ�������������˫���ţ�ͨ�����flag����֤˫�����е�
//�ո������

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		string s;//��ʱ�ַ���
		vector<string> v;
		bool falg = false;//��ʶ�Ƿ�Ϊ""
		for (int i = 0; i < str.size(); i++)
		{
			if (falg)//����
			{
				if (str[i] != '"')
				{
					s += str[i];
				}
				else
					falg = false;
			}
			else
			{
				if (str[i] == ' ')
				{
					//˵���ַ���һ���������
					v.push_back(s);
					s = "";
				}
				else if (str[i] == '"')
				{
					falg = true;
				}
				else
				{
					s += str[i];
				}
			}
		}
		v.push_back(s);
		cout << v.size() << endl;
		for (auto& e : v)
			cout << e << endl;
	}
	return 0;
}