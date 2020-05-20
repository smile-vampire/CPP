#include <iostream>
#include <list>
#include<algorithm>
using namespace std;
//
//void Printflist(list<int>& l)
//{
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << *it << "";
//	}
//	cout << endl;
//}
//void test1()
//{
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//	list<int> copy(lt1);
//	list<int> lt2;
//	lt2 = lt1;
//	Printflist(lt1);
//	Printflist(copy);
//	Printflist(lt2);
//}
//
//void test2()
//{
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//	for (list<int>::reverse_iterator rit = lt1.rbegin(); rit != lt1.rend(); rit++)
//	{
//		cout << *rit << "";
//	}
//	cout << endl;
//}
//
//void test3()
//{
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//	lt1.pop_back();
//	for (auto& e : lt1)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//
//	lt1.push_front(10);
//	lt1.push_front(20);
//	for (auto& e : lt1)
//	{
//		cout << e << "";
//	}
//	cout << endl;
//	lt1.pop_front();
//	for (auto& e : lt1)
//	{
//		cout << e << "";
//	}
//}
//
//void test4()
//{
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//	list<int>::iterator pos = find(lt1.begin(), lt1.end(), 2);
//	if (pos != lt1.end())
//	{
//		pos = lt1.erase(pos);//erase会使迭代器失效
//		lt1.insert(pos, 20);
//	}
//	Printflist(lt1);
//}
//
//void test5()
//{
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//	Printflist(lt1);
//	list<int>::iterator it = lt1.begin();
//	/*while (it != lt1.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = lt1.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}*/
//	for (; it != lt1.end(); it++)
//	{
//		if (*it % 2 == 0)
//		{
//			it = lt1.erase(it);
//		}
//	}
//	Printflist(lt1);
//}
//int main()
//{
//	//test1();
//	////test2();
//	//test3();
//	//test4();
//	test5();
//	return 0;
//}

#include "List.h"
int main()
{
	//test_list1();
	//test_list2();
	//test_list();
	return 0;
}