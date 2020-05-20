#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <queue>


namespace yk
{
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2) { return x1 < x2; }
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x1, const T& x2) { return x1 > x2; }
	};
	template<class T, class contion = vector<T>,class compare = less<T>>
	class queue_priority
	{
	public:
		void AdjustUp(size_t child)
		{
			compare _com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if(_com(_con[parent],_con[child]))
				//if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDown(size_t root)
		{
			compare _com;
			size_t parent = root;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if(child+1<_con.size() && _com(_con[child],_con[child+1]))
					++child;
				//if (_con[child] > _con[parent])
				if(_com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		contion _con;
	};

	void test()
	{
		//queue_priority<int> pq;
		queue_priority<int, vector<int>, greater<int>> pq;
		pq.push(10);
		pq.push(2);
		pq.push(30);
		pq.push(21);
		pq.push(5);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
		
	}
}