//��Ŀ����
//�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ������
//��Ҫ���λʵ���ַ���ͨ������㷨��
//Ҫ��
//ʵ������2��ͨ�����
//* ��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ��
//����ƥ��1���ַ�


//����˼·��
//�������ͨ���ݹ���⡣��ǰ���һ��ƥ�䣬������ͬ�ַ���������ƶ�һ���ַ������ͨ���
//����"?"������ƥ�䣬�Զ�����һ���ַ������ͨ�������"*"�������ƥ���������ַ�������
//0������ʱ����������ѡ��1��ƥ��0����ͨ�������ƶ�һ���ַ����ַ���������2��ƥ��1
//����ͨ������ַ���������ƶ�һ���ַ���3��ƥ������ͨ����������ַ�������ƶ�һ����
//����
//�ݹ����ֹ������ͨ��������ַ�������'\0'��������ͬʱ������


#include <iostream>
#include <string>
using namespace std;
bool match(const char* pattern, const char* str)
{
	//��ǰ�ַ�����������true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//����?�ţ�ƥ��һ���ַ�������һ��λ��
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ��
		�ַ�)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) ||
			match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}