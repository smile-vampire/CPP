

//NowCoder�����ڳ���Σ�պ���ı�������Ϊ�����棬���״η��������룬���ھ��ӵ���Ϣ����
//�������Ǿ����е�һ�����٣���Ҫ�ѷ���������Ϣ������������ṩ����Ľ�����
//��Ϣ���ܵİ취�ǣ�����Ϣԭ���е�ÿ����ĸ���ֱ��ø���ĸ֮��ĵ�5����ĸ�滻
//�����磺��Ϣԭ���е�ÿ����ĸA ���ֱ��滻����ĸF���������ַ��� �䣬������Ϣԭ�ĵ�������ĸ���Ǵ�д�ġ�
//�����е���ĸ��ԭ���е���ĸ��Ӧ��ϵ���¡�
//������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U


//����˼·������ > 'E'
//��ԭ�� = ���� - 5
//���� ԭ�� = ���� + 21

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