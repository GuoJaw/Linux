#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//--------�����----------
//�����������
typedef void(*TIPS)(void);
//�������
struct tip
{
	char* from;
	char* to;
	TIPS tp; //�൱�ڳ�����
};
struct tip* CreateTip(char* from,char* to,TIPS tp)
{
	struct tip* T = (struct tip*)malloc(sizeof(struct tip));
	T->from = (char*)malloc(sizeof(char)*(strlen(from) + 1));
	T->to = (char*)malloc(sizeof(char)*(strlen(to) + 1));
	strcpy(T->from, from);
	strcpy(T->to, to);
	//���ص�������ֵ������ע��ص�����
	T->tp = tp;
	return T;
}
void DestroyTip(struct tip* T)
{
	if (T != NULL)
	{
		if (T->from != NULL)
		{
			free(T->from);
			T->from = NULL;
		}
		if (T->from != NULL)
		{
			free(T->to);
			T->to = NULL;
		}
		free(T);
		T = NULL;
	}
}
//--------ʵ��----------
//�����������������
void Tip1(void){ cout << "TIP: һ��������Ͱݻ��ǹ���" << endl; }
void Tip2(void){ cout << "TIP: ��������ֲ�˼�񣬾ͻѳƲ�����Ϯ���Ͻ�����" << endl; }
void Tip3(void){ cout << "TIP: �������Ȩ׷ɱ�������������" << endl; }

//--------����---------
void open_tip(struct tip* tp)
{
	cout << tp->to << "��" << tp->from << "����" << endl;
	tp->tp(); //��ʱ���ݴ����Ĳ�ͬ���ң����ûص�����,�����˶�̬����
}
int main()
{
	//�����������ҡ���>ע��ص�����
	struct tip* tip1 = CreateTip("���", "����", &Tip1);
	struct tip* tip2 = CreateTip("���", "����", &Tip2);
	struct tip* tip3 = CreateTip("���", "����", &Tip3);

	//���Ʋ����
	cout << "-------------" << endl;
	cout << "1.��������" << endl;
	open_tip(tip1);
	cout << "-------------" << endl;
	cout << "2.�����ֲ�˼��" << endl;
	open_tip(tip2);
	cout << "-------------" << endl;
	cout << "3.����Ȩ׷ɱ" << endl;
	open_tip(tip3);

	system("pause");
}
