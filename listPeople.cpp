
//NowCoderÿ��Ҫ���������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ�
//���ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ���
//���ڸ���һ�������б��������ж�Ŀ���û��Ƿ��ڳ����б��С�
//����ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ�����������Important!����
//��ʾ����ʼ���Ҫ�����ȴ�����

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
int main()
{
	std::string line;
	while (std::getline(std::cin, line)) //��һ�ε����뵽line��
	{
		std::vector<std::string> names; //names�������е�����
		size_t pos = 0;
		while (pos < line.length()) //λ��������ڵ����˳��ȣ���ô֤�������ˣ�˫���ŵ��������������
		{
			if (line[pos] == '\"') //�ҵ�˫����Ҫ����˫�����ڲ�
			{
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1)); //��ȡ�����ŵ�names��
				pos = end + 2;//���������˫���źͶ���
			}
			else
			{
				size_t end = line.find(",", pos + 1);
				if (end == -1) //�Ҳ�������֤���������һ���ַ����ˣ�ֱ�Ӵ�������ַ���������
				{
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; //��������Ķ���
			}
		}
		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find�������������������м���ң����һ��������Ҫ�ҵ�ֵ��
			//�ҵ��˷��ض�Ӧ���������Ҳ����ͷ�������ĩβ��λ�á���������end()��
		{
		printf("Important!\n"); //û�ҵ�
		}
		else
		{
			printf("Ignore\n"); //�ҵ���
		}
	}
	return 0;
}