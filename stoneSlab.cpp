//题目描述
//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
//这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，
//小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K + X(X为K的一个非1和本身的约数)的位置。
//小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
//例如：
//N = 4，M = 24：
//4->6->8->12->18->24
//于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

//解题思路：动态规划，创建vector数组，v[i]表示跳到i处最小步数。初始化数组INT_MAX,如果v[M]==INT_MAX,则
//不能跳到。
//初始状态：v[N] = 0
//转移方程v[i + j] = min(v[i] + 1, v[i + j])   //i为石板编号，j为i的约束

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<int> v(M + 1, INT_MAX);
        v[N] = 0;
        for (int i = N; i <= M; i++)
        {
            if (v[i] == INT_MAX)
                continue;
            for (int j = 2; j < N; j++)
            {
                if (i % j == 0)
                {
                    if (i + j <= M)
                    {
                        v[i + j] = min(v[i] + 1, v[i + j]);
                    }
                    if (i + (i / j) <= M)
                    {
                        v[i + (i / j)] = min(v[i] + 1, v[i + (i / j)]);
                    }
                }
            }
        }
        if (v[M] == INT_MAX)
        {
            v[M] = -1;
        }
        cout << v[M] << endl;
    }
    return 0;
}