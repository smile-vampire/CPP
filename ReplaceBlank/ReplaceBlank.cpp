#include<iostream>
#include<string.h>
using namespace std;


void ReplaceBlank(char string[], int length)
{
	if (string == nullptr || length <= 0)
	{
		return;
	}
	//����ԭ�ַ���ʵ�ʳ���,�ո����
	int oldLength = 0;
	int Blank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++oldLength;
		if (string[i] == ' ')
		{
			++Blank;
		}
		++i;
	}
	

	//�����µ��ַ�������
	int newLength = oldLength + 2 * Blank;
	if (newLength > length)
		return;
	int oldindex = oldLength;
	int newindex = newLength;
	while (oldindex >= 0 && newindex > oldindex)
	{
		if (string[oldindex] == ' ')
		{
			string[newindex--] = '0';
			string[newindex--] = '2';
			string[newindex--] = '%';
		}
		else
		{
			string[newindex--] = string[oldindex];
		}
		--oldindex;
	}
}

//���Դ���
void Test(char* testName, char str[], int length, char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
	const int length = 100;
	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;
	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;
	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;
	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}
int main(int arc,char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
}
