#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		//����һ���ַ����ҳ��ո������
		if (str == NULL || length<0)
			return;
		int i = 0;
		int oldnumber = 0;//��¼��ǰ�ĳ���
		int replacenumber = 0;//��¼�ո������
		while (str[i] != '\0')
		{
			oldnumber++;
			if (str[i] == ' ')
			{
				replacenumber++;
			}
			i++;
		}
		int newlength = oldnumber + replacenumber * 2;//�����ĳ���
		if (newlength>length)//��������ĳ��ȴ����ܳ��Ⱦ��޷�����
			return;
		int pOldlength = oldnumber; //ע�ⲻҪ��һ��Ϊ���ظ���\0��ҲҪ����
		int pNewlength = newlength;
		while (pOldlength >= 0 && pNewlength>pOldlength)//���ַ�
		{
			if (str[pOldlength] == ' ') //�����ո���滻
			{
				str[pNewlength--] = '0';
				str[pNewlength--] = '2';
				str[pNewlength--] = '%';

			}
			else //���ǿո�Ͱ�pOldlengthָ����ַ�װ��pNewlengthָ���λ��
			{
				str[pNewlength--] = str[pOldlength];

			}
			pOldlength--; //������if����elsr��Ҫ��pOldlengthǰ��

		}


	}
};

/*
int main()
{
	Solution solution;
	char* str = "We Are Happy";
	int length = 20;
	cout << str << endl;
	solution.replaceSpace(str,length);
	cout << str << endl;
	system("pause");
	return 0;
}
*/