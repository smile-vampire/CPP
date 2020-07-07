#pragma once
#include <vector>
namespace YK
{
	class ykbitmap
	{
	public:
		ykbitmap(size_t N)//������Χ
		{
			_bitmap.resize(N/32+1,0);
			_num = 0;
		}

		void set(size_t x)//�����1
		{
			size_t index = x / 32;//���ӳ��ĵڼ�������
			size_t pos = x % 32;//���ӳ��ĵڼ�λ

			_bitmap[index] |= (1 << pos);//��posλ��Ϊ1
		}

		void reset(size_t x)//ɾ����0
		{
			size_t index = x / 32;
			size_t pos = x % 32;

			_bitmap[index] &= ~(1 << pos);
		}

		bool test(size_t x)//�ж�x�ڲ���(Ҳ�����жϸ�λ�Ƿ�Ϊ1)
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
		size_t _num;//ӳ���������
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
