#pragma once
#include<assert.h>

namespace yk
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		vector(const vector<T>& v)
		{
			_start = new T[v.size()];
			_finish = _start + v.size();
			_endofstorage = _start + v.size();

			memcpy(_start, v._start, sizeof(T) * v.size());
		}

		// x = copy
		vector<T>& operator=(vector<T> v)
		{
			this->swap(v);
			return *this;
		}

		// v1.swap(v2)
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sz * sizeof(T));
					delete[] _start;
				}
				_start = tmp;

				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void push_back(const T& val)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newcapacity);
			}

			*_finish = val;
			++_finish;
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		};

		void insert(iterator pos, const T& val)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newcapacity);
				//增容后pos失效 重置pos
				pos = len + _start;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
		};

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;

			return pos;
		}
		
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish-1;
		}
		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.pop_back();
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.insert(v.begin()+1, 20);
		v.erase(v.end());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
}

