//一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，
//计算一下能从花布条中尽可能剪出几块小饰条来呢？


//解题思路：
//用STL的string库可以通过find函数找，找到以后跳过一个T串的长度。例如：在
//abcacbcbcabscbc中找cbc，第一次找到了这个位置：abcacbcbcabscbc，找到这个下标后，会跳过整体cbc，也
//就是从这个位置继续找：abcacbcbcabscbc，否则如果你只跳一个字符，会导致cbcbc会被算成2次，而按照本题
//的题意，应该算一次。

#include<iostream>
#include<string>
int main()
{
	std::string s, t;

	while (std::cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		//依次在 s 中查找 t 即可，直到再也找不到 t
		while ((pos = s.find(t, pos)) != std::string::npos)
		{
			pos += t.size(); //跳过t串整体的长度
			++res; //计数
		}
		std::cout << res << std::endl;
	}

	return 0;
}