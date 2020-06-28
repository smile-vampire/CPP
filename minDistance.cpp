//��Ŀ����
//Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������������ɵı༭
//����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ����༭������㷨�������ɶ����ѧ��Levenshtein
//����ģ����ֽ�Levenshtein Distance��
//Ex��
//�ַ���A : abcdefg
//�ַ���B : abcdef
//ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ�����
//���롣
//Ҫ��
//�������������ַ�����д��һ���㷨�������ǵı༭���롣


//������˼·����
//������Ҫ�ö�̬�滮���� ״̬�� ��״̬��word1��ǰ1��2��3��...m���ַ�ת����word2��ǰ1��2��3��...n
//���ַ���Ҫ�ı༭����
//F(i, j) :word1��ǰi���ַ���word2��ǰj���ַ��ı༭���� ״̬���ƣ� F(i, j) = min{ F(i - 1,j�� + 1, F(i,j - 1) + 1, F(i -
//1,j - 1) + (w1[i] == w2[j] ? 0 : 1) } ��ʽ��ʾ��ɾ�������Ӻ��滻������ѡ��һ����С������ F(i - 1, j) : w1[1, ..., i - 1]��
//w2[1, ..., j]�ı༭���룬ɾ��w1[i]���ַ�--->F(i, j) F(i, j - 1) : w1[1, ..., i]��w2[1, ..., j - 1]�ı༭���룬����һ���ַ�-- -
//> F(i, j) F(i - 1, j - 1) : w1[1, ..., i - 1]��w2[1, ..., j - 1]�ı༭���룬���w1[i]��w2[j]��ͬ�� �����κβ������༭���벻
//�䣬���w1[i]��w2[j]��ͬ���滻w1[i]���ַ�Ϊw2[j]--->F(i, j) ��ʼ���� ��ʼ��һ��Ҫ��ȷ����ֵ���������
//������մ�����ʼֵ�޷�ȷ�� F(i, 0) = i : word��մ��ı༭���룬ɾ������ F(0, i) = i : �մ���word�ı༭��
//�룬���Ӳ��� ���ؽ����F(m, n)


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minDistance(string word1, string word2) {
	// word��մ�֮��ı༭����Ϊword�ĳ���
	if (word1.empty() || word2.empty()) {
		return max(word1.size(), word2.size());
	}
	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)��ʼ��
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i) {
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i) {
		f[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			// F(i,j) = min { F(i-1,j��+1, F(i,j-1) +1, F(i-1,j-1) +
			//(w1[i]==w2[j]?0:1) }
			// �ж�word1�ĵ�i���ַ��Ƿ���word2�ĵ�j���ַ����
			if (word1[i - 1] == word2[j - 1]) {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// �ַ���ȣ�F(i-1,j-1)�༭���벻��
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// �ַ�����ȣ�F(i-1,j-1)�༭���� + 1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}
int main() {
	string a, b;
	while (cin >> a >> b)
		cout << minDistance(a, b) << endl;
	return 0;
}