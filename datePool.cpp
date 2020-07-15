
//Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。为了提高性能，
//架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，系统会创建一个新连接，
//当请求处理完成时该连接会被放入连接池中，供后续请求使用。
//
//现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接



//解题思路
//1. 服务器后台访问数据库时，需要先连上数据库，而为了连上数据库，需要连接方和数据库服务上各自都
//要维护链接，而链接本身的创建维护是有成本的
//2. 要减少开销，这里的解决方案就是将以前的mysql链接复用起来，从而节省了创建和销毁的时间成本，
//该题目就是想让你根据算法，结合日志，计算当前的业务需要预先创建多少链接，来满足正常使用
//使用一个set来做，如果某个记录是connect，就加到set中去，如果是disconnect，就把set中对应的值删除
//掉。在加进去的过程中，不断判断set元素的最大个数，最终返回这个最大个数即可。

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		set<string> pool;
		string id, con;
		int maxSize = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> id >> con;
			if (con == "connect") pool.insert(id);
			else if (con == "disconnect") pool.erase(id);
			int size = pool.size();
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0;
}