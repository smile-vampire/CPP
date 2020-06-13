//题目描述
//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，
//为 - 1代表是对方玩家的棋子。

//解题思路：
//井字棋有四种情况表示当前玩家获胜，1代表当前玩家棋子 1. 行全为1， 即行的和为3 2. 列全为1， 列的和为
//3 3. 主对角全为1， 对角和为3 4. 副对角全为1， 对角和为3 5. 如果扩展为N * N的话，判断和是否等于N，下
//面代码适用任何情况
#include <iostream>
#include <vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		int row = board.size();
		//检查每一行的和是是否等于row
		int i, j, sum;
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}
		//检查每一列的和是是否等于row
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}
		//检查主对角线的和是是否等于row
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
			return true;
		//检查副对角线的和是是否等于row
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
			return true;
		return false;
	}
};

int main()
{
	vector<vector<int> > board;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			cin >> board[i][j];
		}
	}
	Board B;
	cout << B.checkWon(board) << endl;
	return 0;
}