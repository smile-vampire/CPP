#include<iostream>
#include<string.h>
using namespace std;


void ReplaceBlank(char string[], int length)
{
	if (string == nullptr || length <= 0)
	{
		return;
	}
	//计算原字符串实际长度,空格个数
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
	

	//计算新的字符串长度
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

//测试代码
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

// 空格在句子中间
void Test1()
{
	const int length = 100;
	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
	const int length = 100;
	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
	const int length = 100;
	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
	const int length = 100;
	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
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
