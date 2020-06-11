//��Ŀ����
//������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷���
//1.�����ַ������ֵ����������磺
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.�����ַ����ĳ����������磺
//"car" < "cats" < "koala" < "doggies" < "carriage"
//������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

//����˼·��
//�����յ��ַ������ŵ�vector�����У�����string��operator >= �������������ascii�Ƚ��ַ�
//��������string��size���Ƚ��ַ����ĳ���

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v)
		cin >> str;
	bool lenSym = true, lexSym = true;
	// ����Ҫע���i=1��ʼ������ǰ��Ƚϣ��Ƚϳ���
	for (size_t i = 1; i < v.size(); ++i)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			lenSym = false;
			break;
		}
	}
	//�Ƚ�ASCII��
	for (size_t i = 1; i < v.size(); ++i)
	{
		if (v[i - 1] >= v[i])
		{
			lexSym = false;
			break;
		}
	}
	if (lenSym && lexSym)
		cout << "both" << endl;
	else if (!lenSym && lexSym)
		cout << "lexicographically" << endl;
	else if (lenSym && !lexSym)
		cout << "lengths" << endl;
	else if (!lenSym && !lexSym)
		cout << "none" << endl;
	return 0;
}