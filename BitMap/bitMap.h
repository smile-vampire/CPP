#pragma once
#include <vector>
namespace YK
{
	class ykbitmap
	{
	public:
		ykbitmap(size_t N)//给定范围
		{
			_bitmap.resize(N/32+1,0);
			_num = 0;
		}

		void set(size_t x)//添加置1
		{
			size_t index = x / 32;//算出映射的第几个整形
			size_t pos = x % 32;//算出映射的第几位

			_bitmap[index] |= (1 << pos);//将pos位置为1
		}

		void reset(size_t x)//删除置0
		{
			size_t index = x / 32;
			size_t pos = x % 32;

			_bitmap[index] &= ~(1 << pos);
		}

		bool test(size_t x)//判断x在不在(也就是判断改位是否为1)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			if (_bitmap[index] & (1 << pos))
				return true;
			else
				return false;
		}
	private:
		std::vector<int> _bitmap;
		size_t _num;//映射多少数据
	};

	void test()
	{
		ykbitmap bm(100);
		bm.set(3);
		bm.set(33);
		bm.set(50);
		bm.set(88);
		bm.set(98);
		for (size_t i = 0; i < 100; i++)
		{
			printf("[%d]: %d\n", i, bm.test(i));
		}
	}
}
