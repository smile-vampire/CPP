

//NowCoder生活在充满危险和阴谋的年代。为了生存，他首次发明了密码，用于军队的消息传递
//假设你是军团中的一名军官，需要把发送来的消息破译出来、并提供给你的将军。
//消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换
//（例如：消息原文中的每个字母A 都分别替换成字母F），其他字符不 变，并且消息原文的所有字母都是大写的。
//密码中的字母与原文中的字母对应关系如下。
//密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U


//解题思路：密码 > 'E'
//则：原文 = 密码 - 5
//否则： 原文 = 密码 + 21

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        string res;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'F' && str[i] <= 'Z')
                res += str[i] - 5;
            else if (str[i] >= 'A' && str[i] <= 'E')
                res += str[i] + 21;
            else
                res += ' ';
        }
        cout << res << endl;
    }
    return 0;
}