//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
//�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
//�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ���������
//������Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���磺
//A = ��aba����B = ��b����������4�ְ�B����A�İ취��
//* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
//* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//* ����ĸ��b��֮�� : "abba" �ǻ���
//* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//�������������Ĵ�Ϊ2

//������˼·����
//����ʹ�ñ�����ⷽʽ���㼴�ɣ�����str1����str2 insert����str1��ÿ��λ�ã��ж��Ƿ��ǻ��ģ��Ǿ�
//++count����Ҫע��������ﲻ�� str1.insert(i, str2)�������Ļ�str1�ı��ˣ��ж���һ��λ�þͲ����ˡ���
//��ÿ��ʹ��str1��������һ��str��Ȼ��str.insert(i, str2)�����жϡ�

#include <iostream>
#include <string>
using namespace std;

// �ж��Ƿ��ǻ���
bool IsCircleText(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		++begin;
		--end;
	}
	return true;
}
int main()
{
	std::string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	
	size_t count = 0;
	for (size_t i = 0; i <= str1.size(); ++i)
	{
		// ���ַ���2���뵽�ַ���1��ÿ��λ�ã����ж��Ƿ��ǻ���
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
			++count;
	}
	cout << count << endl;
	return 0;
}
