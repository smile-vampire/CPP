
//�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼�� / usr / local / bin����
//����Ҫ�˴δ����� / usr������ / usr / local���Լ��� / usr / local / bin�������ڣ�Linux��mkdir�ṩ��
//ǿ��ġ� - p��ѡ�ֻҪһ�����mkdir - p / usr / local / bin�������Զ�������Ҫ���ϼ�Ŀ¼��
//���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir - p�����



//����˼·
//1. ����Ŀ��Ҫ���˽� mkdir - p �����������Եݹ鴴��Ŀ¼
//2. ���Ǹ���Ŀ��ʵ�������ǽ���������ǣ�����һ�����ݣ��������Ŀ������ô�����ٵ� mkdir - p ����
//��������Ҫ�Ķ��Ŀ¼
//ֻҪ�������棬��ǰ׺�ַ���·������ͬ·���޳���ֻmkdir ��p�����Ψһ·���Ϳ��Խ���������


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) cin >> list[i];
		sort(list.begin(), list.end()); //�������ַ����������򣬷���һ��
		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1��������ͬ
			// 2��ǰ���Ǻ󴮵��Ӵ������Һ󴮺�һλ�� '/'
			if (list[i] == list[i + 1]) flag[i] = false;
			else if (list[i].size() < list[i + 1].size() && 
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1]
				[list[i].size()] == '/')
				flag[i] = false;
		}
		for (int i = 0; i < list.size(); ++i)
			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	}
	return 0;
}