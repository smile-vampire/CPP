//�ֵܵ��ʵĺ���: �������ʲ�ͬ, ������ͬ, ���ǹ��ɵ���ĸ˳����ͬ
//�������� : �������ֵ��е��ʵĸ���n��������n��������Ϊ�ֵ䵥�ʡ� ������һ�����ʣ����������ֵ�����
//�ܵ��ʵĸ���m ����������k
//������� : �������룬������ҵ����ֵܵ��ʵĸ���m Ȼ��������ҵ����ֵܵ��ʵĵ�k�����ʡ� ע��!!һ��
//Ҫ��ע���շ��صĵ� k ���������������, ���ܸ��.
//����˵���� "�ֵ�", ���Ҫ������ĵ��ʰ����ֵ�������~����õ��� k ���������
//����˼·��
//1. ���ֵ��еĵ����ȷŵ� vector ��
//2. �� vector ��������
//3. isBrother ���������ж�ÿ������ĵ����Ƿ����ֵܵ���
//4. �ж��ֵܵ��ʵĹ�����
//1. ���ж�����
//2. ���������ͬ, �ٿ��Ƿ�����ȫ��ͬ(��ȫ��ͬ�����ֵ�)
//3. Ȼ��������������, ������ͬ�������ֵܵ���.



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// �ж����������Ƿ����ֵܵ���
bool isBrother(string str, string s) {
	// 1. ���ж������Ƿ���ͬ. ����ͬ��һ�������ֵܵ���
	if (str.size() == s.size()) {
		// 2. ���ж��ַ����Ƿ���ȫ��ͬ. ��ͬ��Ҳ�����ֵ�����
		if (str == s)
			return false;
		// 3. ��������������. �������ͬ�����ֵܵ���(��˲��������� const&)
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	}
	return false;
}
int main() {
	int num;
	while (cin >> num) {
		string str;
		string word, s;
		int index;
		vector<string> vs;
		// ��ȡ�ֵ��еĵ���, ���ֵ�ŵ� vs ��.
		for (int i = 0; i < num; ++i) {
			cin >> str;
			vs.push_back(str);
		}
		// [ע��!!] ����˵���� "�ֵ�", ���Ҫ������ĵ��ʰ����ֵ�������~����õ��� k ���������.
		sort(vs.begin(), vs.end());
		// ����Ҫ�ж��Ĵʺ�k
		cin >> word;
		cin >> index;
		int counts = 0;
		// ͳ���ֵ��д��ڶ��ٸ��ֵܵ���.
		for (int i = 0; i < num; ++i) {
			if (isBrother(word, vs[i])) {
				counts++;
				// ���� k ���ֵܵ��ʱ��浽 s ��.
				if (counts == index)
					s = vs[i];
			}
		}
		// ���������
		if (!vs.empty())
			cout << counts << endl;
		if (counts >= index)
			cout << s << endl;
	}
	return 0;
}