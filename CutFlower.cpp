//һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�������С������
//����һ���ܴӻ������о����ܼ�������С�������أ�


//����˼·��
//��STL��string�����ͨ��find�����ң��ҵ��Ժ�����һ��T���ĳ��ȡ����磺��
//abcacbcbcabscbc����cbc����һ���ҵ������λ�ã�abcacbcbcabscbc���ҵ�����±�󣬻���������cbc��Ҳ
//���Ǵ����λ�ü����ң�abcacbcbcabscbc�����������ֻ��һ���ַ����ᵼ��cbcbc�ᱻ���2�Σ������ձ���
//�����⣬Ӧ����һ�Ρ�

#include<iostream>
#include<string>
int main()
{
	std::string s, t;

	while (std::cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		//������ s �в��� t ���ɣ�ֱ����Ҳ�Ҳ��� t
		while ((pos = s.find(t, pos)) != std::string::npos)
		{
			pos += t.size(); //����t������ĳ���
			++res; //����
		}
		std::cout << res << std::endl;
	}

	return 0;
}