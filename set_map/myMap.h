#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "RBTree.h"

namespace yk
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return  _t.end();
		}

		pair<iterator, bool> Insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};

	void test_map()
	{
		/*map<int, int> m;
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(3, 3));
		m.Insert(make_pair(10, 10));
		m.Insert(make_pair(5, 5));
		m.Insert(make_pair(6, 6));

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto kv : m)
		{
			cout << kv.first << ":" << kv.second << endl;
		}

		cout << endl;*/

		string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
		map<string, int> countMap;
		for (auto& str : strs)
		{
			// 1、如果水果不在map中，则operator[]会插入pair<str, 0>, 返回映射对象(次数)的引用进行了++。
			// 2、如果水边在map中，则operator[]返回水果对应的映射对象(次数)的引用，对它++。
			countMap[str]++;
		}

		for (auto kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}


