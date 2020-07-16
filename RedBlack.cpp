//��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�
//ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש.


//ÿ�����ݵ�һ������������ m �� n��1��m, n��20���������� m �У�ÿ�а��� n ���ַ���ÿ���ַ���ʾһ���ש����ɫ���������£�
//
//1. ��.������ɫ�Ĵ�ש��
//2. ��#������ɫ�Ĵ�ש��
//3. ��@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ��


//
//����˼·
//1. �����m��n���Ǵ���������������뼸�м����ַ�
//2. �ڶ��п�ʼ��������ַ��������ǵġ����߾��󡱣����С�.��->��ɫ�Ĵ�ש, ��#��->��ɫ�Ĵ�ש, ��@��->��ɫ�Ĵ�
//ש��������վ������ש��
//3. �����ĺ��������ǣ�����վ��λ�ÿ�ʼ�����ܱ�����λ���ߣ�����ֱ���߹��ĺ�ɫ��ש�������Ƕ���
//��������Բ��ù�����ȱ����ķ�ʽ��



#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
struct pos { int x, y; };
int bfs(vector<vector<char> >& map, vector<vector<bool> >& visit, pos& start)
{
	const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pos> que;
	int count = 0;
	int m = map.size(), n = map[0].size();
	que.push(start);
	visit[start.x][start.y] = true; ++count;
	while (!que.empty())
	{
		pos cur = que.front(), next;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
				++count;
			}
		}
	}
	return count;
}
int main()
{
	int m, n;
	while (cin >> m >> n && (m * n))
	{
		pos start;
		vector<vector<char> > map(m, vector<char>(n));
		vector<vector<bool> > visit(m, vector<bool>(n));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				visit[i][j] = false;
				cin >> map[i][j];
				if (map[i][j] == '@')
					start.x = i, start.y = j;
			}
		cout << bfs(map, visit, start) << endl;
	}
	return 0;
}