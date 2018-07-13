#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//--------抽象层----------
//定义锦囊类型
typedef void(*TIPS)(void);
//定义锦囊
struct tip
{
	char* from;
	char* to;
	TIPS tp; //相当于抽象类
};
struct tip* CreateTip(char* from,char* to,TIPS tp)
{
	struct tip* T = (struct tip*)malloc(sizeof(struct tip));
	T->from = (char*)malloc(sizeof(char)*(strlen(from) + 1));
	T->to = (char*)malloc(sizeof(char)*(strlen(to) + 1));
	strcpy(T->from, from);
	strcpy(T->to, to);
	//给回调函数赋值，即：注册回调函数
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
//--------实现----------
//诸葛亮定义三个锦囊
void Tip1(void){ cout << "TIP: 一来到东吴就拜会乔国老" << endl; }
void Tip2(void){ cout << "TIP: 如果主公乐不思蜀，就谎称曹贼来袭，赶紧回来" << endl; }
void Tip3(void){ cout << "TIP: 如果被孙权追杀，向孙尚香求救" << endl; }

//--------调用---------
void open_tip(struct tip* tp)
{
	cout << tp->to << "打开" << tp->from << "锦囊" << endl;
	tp->tp(); //此时根据传进的不同锦囊，调用回调函数,发生了多态现象
}
int main()
{
	//创建三个锦囊——>注册回调函数
	struct tip* tip1 = CreateTip("诸葛", "赵云", &Tip1);
	struct tip* tip2 = CreateTip("诸葛", "赵云", &Tip2);
	struct tip* tip3 = CreateTip("诸葛", "赵云", &Tip3);

	//赵云拆锦囊
	cout << "-------------" << endl;
	cout << "1.来到东吴" << endl;
	open_tip(tip1);
	cout << "-------------" << endl;
	cout << "2.主公乐不思蜀" << endl;
	open_tip(tip2);
	cout << "-------------" << endl;
	cout << "3.被孙权追杀" << endl;
	open_tip(tip3);

	system("pause");
}
