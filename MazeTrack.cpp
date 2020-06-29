//��Ŀ����
//����һ����ά����N* M������2 <= N <= 10; 2 <= M <= 10������5 �� 5��������ʾ��
//int maze[5][5] = {
//        0, 1, 0, 0, 0,
//        0, 1, 0, 1, 0,
//        0, 0, 0, 0, 0,
//        0, 1, 1, 1, 0,
//        0, 0, 0, 1, 0,
//};
//
//
//����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ���
//�½ǵ����·�ߡ���ڵ�Ϊ[0, 0], �ȵ�һ�ո��ǿ����ߵ�·��
//Input
//һ��N �� M�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ��, �������ж�����������Թ�ֻ��һ��ͨ����
//Output
//���Ͻǵ����½ǵ����·������ʽ��������ʾ��
//Sample Input
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0
//Sample Output
//(0, 0)
//(1, 0)
//(2, 0)
//(2, 1)
//(2, 2)
//(2, 3)
//(2, 4)
//(3, 4)
//(4, 4)

//����˼·��
//������û��ݷ���� ���岽��Ϊ��
//1. ���Ƚ���ǰ�����·����������Ϊ����
//2. �жϵ�ǰ���Ƿ�Ϊ���ڣ��������·��������������ת��4
//3. �����жϵ�ǰ����ϡ��¡������ĸ����Ƿ���ߣ����������ݹ��߸õ�
//4. ��ǰ���Ƴ�·��������Ϊ����

#include<iostream>
#include<vector>
using namespace std;
int N, M; //�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����
		if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
			if (path_best.empty() || path_temp.size() < path_best.size())
				path_best = path_temp;
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0; //�ָ��ֳ�����Ϊδ��
	path_temp.pop_back();
}
int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto& i : maze)
			for (auto& j : i)
				cin >> j;
		MazeTrack(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	}
	return 0;
}