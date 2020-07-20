//NowCoder��ϲ�����ֳ����Թ���Ϸ������С����Ǳ���˭���߳��Թ���
//���ڰ��Թ��ĵ�ͼ���㣬���ܰ����������߳��Թ���Ҫ���ٲ���

//ÿ�����ݰ���һ��10 * 10���ɡ�#���͡�.����ɵ��Թ������С�#������ǽ����.������ͨ·��
//����ڵ�һ�еڶ��У����������һ�еھ��С�
//������һ����.���㶼��һ���ߵ����������ĸ�����ġ�.���㡣


//����˼·
//1. ����һ����ά���飬���ϵĽ����Թ���ͼ(��Ϊ�ж����ͼ)����ȡ���Թ���ͼ�󣬲��ù�����ȷ�ʽ��
//�Թ����ҵ��ĵ�һ��·��һ������̵�·�����������������һ����
//2. �ṹ�趨��
//pos��x��y��ʾ��ǰ����λ�ã�level����������
//dir : ��ʾ��ǰλ�õ��ϡ��¡������ĸ�����
//queue : ������ȱ�������Ҫ�õ����У���������·��
//visit�����߹���·�����б��
//start��end��ʾ��ںͳ���
//3. ���ù�����ȷ�ʽ���Թ�����start����У��Ը�λ�ý��б�ǣ�ֻҪ���в�Ϊ�գ��������²��裬ֱ��
//������ڣ�
//�Ӷ�����ȡ����ǰλ��cur�������λ�õ��ϡ��¡��������ĸ����򣬼���Ҫ�ߵ���һ��
//���next�ڳ��ڵ�λ�ã��Ѿ��ҵ��������߲���level
//���������λ����Ч(�����ڵ�ͼ��)����ǽ(��λ���ַ�Ϊ'.')������û���߹�(visit���Ϊfalse)
//ʱ������λ������У��ټ���������������


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
struct pos { int x, y, level; };
int bfs(vector<vector<char> >& map)
{
	const int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
	queue<pos> que;
	int m = map.size(), n = map[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));
	pos start{ 0,1,0 }, end{ 9,8,0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty())
	{
		pos cur = que.front(), next; //����cur��next
		que.pop();
		for (int i = 0; i < 4; ++i) //BFS,�����ĸ������������
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y)
				return next.level;
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
	return 0;
}
int main()
{
	vector<vector<char> > map(10, vector<char>(10));
	while (cin >> map[0][0]) //�ɶ��������������Ҫȫ����ȡ
	{
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j)
			{
				if (i == 0 && j == 0) continue;
				cin >> map[i][j];
			}
		cout << bfs(map) << endl;
	}
	return 0;
}