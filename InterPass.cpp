
//星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，通过一张表里的信息
//映射成最终4位密码。表的规则是：n对应的值是矩阵X的n次方的左上角，如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
//| 1 1 | ^ n = > | Xn ..|
//|1 0|      |.. .. |
//例如n = 2时，
//| 1 1 | ^ 2 = > | 1 1 | *| 1 1 | = > | 2 1|
//|1 0|      |1 0|   |1 0|    |1 1 |
//即2对应的数是“0002”。

//解题思路：初始化斐波那契数列，每次获取对应数据，打印最后4位即可

#include <iostream>
#include <vector>
using namespace std;
std::vector<int> a = { 1,1 };
void data_init()
{
	int i;
	for (i = 2; i < 10005; i++) {
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
}
int main()
{
	int n, t;
	data_init();
	while (std::cin >> n) {
		while (n--) {
			std::cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}