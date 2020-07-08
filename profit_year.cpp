//NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
//���ڸ���һ��ʱ�����䣬������������������ж��١�

//����˼·��
//��Ȼ��һ����������ڼ��������Ǿ�дһ�����ڼ�������Ȼ������޸ļ��ɡ���ô�����ڼ�������ôд�أ�
//���ڼ������Ļ������ǽ�������ڼ����Ϊ�������֣���һ������һ�����ݣ����һ������һ�����ݣ����м�
//��������ݡ������������ֻ��Ҫ�ж�������365��366�����ˡ������꣬���Ǿ�Ҫ��������������һ��ĵ�
//���졣����Ҫ�����1994��5��27�յ�2003��4��29�գ���ô�����Ǿ�Ҫ�����5��27������һ��ĵڼ��죬Ȼ��
//�ж�1994�겻�����꣬���ǣ�������365��ȥ����������͵õ�����ˡ������е�һ��ҲҪ�㣬���Ի�Ҫ������һ
//�졣Ȼ�������4��29����2003��ĵڼ��죬�Ϳ��Խ�������ˡ����ԣ�������Ҫһ�������������Ǹ���һ������
//�գ����������һ��ĵڼ��졣


#include <cstdio>
#include <cmath>
#include <iostream>
//�����жϺ���
inline int leap_year(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
//��������
inline int profit_of_year(int year)
{
	return 2 * 31
		+ 1 * 28
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 31
		+ 2 * 30
		+ 2 * 31
		+ 1 * 30
		+ 2 * 31
		+ leap_year(year);
}
//�ж�����·��ǲ���������
inline bool prime(int n)
{
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
}
//���һ����������һ��ĵڼ���
int profit_of_this_year(int year, int month, int day)
{
	if (!prime(month))
	{
		day *= 2;
	}
	while (--month)
	{
		switch (month)
		{
		case 1:
		case 8:
		case 10:
		case 12:
			day += 62;
			break;
		case 3:
		case 5:
		case 7:
			day += 31;
			break;
		case 4:
		case 6:
		case 9:
			day += 60;
			break;
		case 11:
			day += 30;
			break;
		case 2:
			day += 28 + leap_year(year);
			break;
		default:;
		}
	}
	return day;
}
int main()
{
	int year1, month1, day1, year2, month2, day2;
	int count_profit = 0;

	while (std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		count_profit = 0;
		count_profit += profit_of_year(year1) -
		profit_of_this_year(year1, month1, day1 - 1);
		//�����day1 - 1��Ȼ�п��ܻ����0�գ�����ʵ��2��0�վ��൱��1��31�գ����Բ�Ӱ������
		count_profit += profit_of_this_year(year2, month2, day2);
		if (year1 == year2) //���������յ���ͬһ�꣬�����ͬһ�꣬Ҫ������һ���������
		{
		count_profit -= profit_of_year(year1);
		}
		for (int i = year1 + 1; i < year2; i++) //�м�����ÿһ�������
		{
		count_profit += profit_of_year(i);
		}
		std::cout << count_profit << std::endl;
	}
  return 0;
}