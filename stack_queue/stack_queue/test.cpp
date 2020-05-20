#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
//#include <stack>
//#include <queue>


namespace yk
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};

	void test1()
	{
		//stack<int, vector<int>> s;
		//stack<int, list<int>> s;
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}

	template<class T, class Contain = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		T& front()
		{
			return _con.front();
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		Contain _con;
	};

	void test2()
	{
		//queue<int, list<int>> q;
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}

int main()
{
	yk::test1();
	yk::test2();
	return 0;
}