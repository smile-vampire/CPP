
//��C / C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣C���Է��ʹ���»��߷ָ�������ʣ�
//���硰hello_world������Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
//���������ĳ���Ա���Զ�ת��������


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <exception>
#include <iomanip>
#include <memory>
#include <sstream>
#define INF 1000000
using namespace std;
int main(int argc, char** argv)
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			// 1. ���� _ ��ֱ������
			if (s[i] == '_') continue;
			// 2. �����һ���ַ��� _ ����һ���ַ�תΪ��д��ĸ
			if (i > 0 && s[i - 1] == '_') cout << (char)toupper(s[i]);
			else cout << s[i];
		}
			cout << endl;
	}
	return 0;
}