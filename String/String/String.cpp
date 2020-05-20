#include<iostream>
#include<assert.h>
using namespace std;

namespace yk
{
	class String
	{
	public:
		String(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new(char[_capacity + 1]);
			strcpy(_str, str);
		}

		~String()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//s1(s)
		/*String(const String& s)
		{
			_str = new(char[s._size + 1]);
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._size;
		}*/
		//现代写法
		String(const String& s)
			:_str(nullptr)
		{
			String tmp(s._str);
			swap(_str, tmp._str);
		}

		//s1=s2
		/*String& operator=(const String& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new(char[s._size + 1]);
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._size;
			}
			return *this;
		}*/
		//现代写法
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		//增容多大
		void reverse(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new(char[n + 1]);
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}
		//s1.push_back('x')
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reverse(_capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//s1.append("xxxxxxxxxxxx")
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reverse(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		//s1+='x';
		String& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		//s1+="xxxxx";
		String& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		void resize(size_t n, char  ch = '\0')
		{
			if (n < _size)
			{
				//删除数据
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				//插入数据
				if (n > _capacity)
				{
					//空间不够
					reverse(n);
				}
				//填补数据
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		String& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_capacity == _size)
			{
				reverse(_capacity * 2);
			}
			for (size_t i = _size; i >= pos; i--)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		String& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			int len = strlen(str);
			if (len + _size > _capacity)
			{
				reverse(len + _size);
			}
			for (size_t i = _size; i >= pos; i--)
			{
				_str[i + len] = _str[i];
			}
			strncpy(_str + pos, str, len);
			_size = len + _size;
			return *this;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos >= 0 && pos < _size);
			if (_size - pos <= len)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size = _size - len;
			}
		}
		void find(char ch);
		void find(const char* str);
		bool operator<(const String& s);
		bool operator==(const String& s);
		bool operator>(const String& s);

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t String::npos = -1;
	ostream& operator<<(ostream& out, const String& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}

	istream& operator>>(istream& in, String& s);
}


int main()
{
	yk::String s("hello");
	s.push_back('x');
	s.push_back('y');
	s.append("world");
	s += 'k';
	s += "today";
	cout << s << endl;

	for (size_t i = 0; i < s.size(); i++)
	{
		s[i] += 1;
		cout << s[i] << " ";
	}
	cout << endl;

	yk::String::iterator it = s.begin();
	while (it != s.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//范围for
	for (auto& ch : s)
	{
		ch += 1;
		cout << ch << " ";
	}
	cout << endl;
	
	yk::String s1("helloword");
	/*s1.resize(5);
	cout << s1 << endl;*/
	s1.resize(15);
	cout << s1 << endl;

	yk::String s2("hello");
	s2.insert(1, 'x');
	s2.insert(2, '!');
	cout << s2 << endl;

	yk::String s3("hello");
	s3.insert(1, "hello");
	cout << s3 << endl;

	yk::String s4("hello");
	s4.erase(0, 2);
	cout << s4 << endl;
	return 0;
}