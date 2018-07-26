
#include<assert.h>
#include<iostream>
using namespace std;

typedef struct LinkNode{
	struct LinkNode* next;
	int data;
}LinkNode;
//创建节点
LinkNode* createLink(){
	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
	head->next = NULL;
	LinkNode* ptr = head;
	int data;
	while (1){
		cout << "请输入data=";
		cin >> data;
		if (data == -1)
			break;
		//创建新节点
		LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
		newNode->data = data;
		newNode->next = NULL;
		//在尾部插入新节点newNode
		ptr->next = newNode;
		//ptr指针指向新的尾部节点
		ptr = newNode;
	}
	return head;
}
//获取中间节点
LinkNode* getMidNode(LinkNode* head){
	assert(head != NULL);
	if (head->next == NULL) //链表没有有效节点,返回NULL
		return NULL;
	//【初始化】
	LinkNode* slow = head->next;  //slow指向第一个有效节点
	LinkNode* fast = head->next->next; //fast指向第二个有效节点
	while (fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
/*
判断单链表是否有环：
如果有，返回入环的第一个点
如果没有，返回NULL
*/
LinkNode* isLoop(LinkNode* head){
	assert(head != NULL);
	//【初始化】
	LinkNode* slow = head;
	LinkNode* fast = head;
	while (fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (slow != fast)//不相等，说明无环
		return NULL;
	//在相遇位置，使快指针指向head，之后快慢指针都一次走一步，下一次相交点就是第一个入环点
	fast = head;
	while (fast != slow){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
//单链表的倒置
LinkNode* reverse(LinkNode* head){
	if (head->next == NULL) //如果没有有效节点
		return head;
	if (head->next->next == NULL)
		return head;  //只有一个有效节点
	//【初始化】
	LinkNode* pre = head->next;
	LinkNode* cur = head->next->next; //cur指向第二个有效节点
	while (cur != NULL){
		LinkNode* last = cur->next;
		cur->next = pre;
		pre = cur;
		cur = last;
	}
	head->next->next = NULL;
	head->next = pre;
	return head;
}
//遍历
void travel(LinkNode* head){
	LinkNode* cur = head->next;//cur指向第一个有效节点
	while (cur){
		cout << cur->data << "  ";
		cur = cur->next;
	}
}
//有序链表的合并:将L2中的节点插入到L1中
LinkNode* mergeL1L2(LinkNode* L1, LinkNode* L2){
	assert((L1 != NULL) && (L2 != NULL));
	//初始化L1和L2的前驱节点/当前节点的指针
	LinkNode* p1 = L1; LinkNode* c1 = L1->next;
	LinkNode* p2 = L2; LinkNode* c2 = L2->next;
	while (c1 && c2){ 
		if (c1->data <= c2->data){
			p1 = c1; c1 = c1->next;
		}
		else{//将L2的节点c2插入L1中
			//1.保存c2的后继
			LinkNode* tmp = c2->next;
			//2.将c2插入L1
			c2->next = c1; p1->next = c2;
			//3.更新p1/c1和p2/c2（注意：c1位置不变）
			p1 = p1->next; p2->next = tmp; c2 = tmp;
		}
	}
	if (p2 != NULL) //如果L2链表不空
		p1->next = c2;
	free(L2);
	return L1;
}
void test01(){
	LinkNode* head = createLink();
	LinkNode* mid = getMidNode(head);
	head = reverse(head);
	travel(head);
	system("pause");
}
void test02(){  //环形单链表
	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* node1 = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* node2 = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* node3 = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* node4 = (LinkNode*)malloc(sizeof(LinkNode));
	head->next = node1; 
	node1->next = node2; node1->data = 1;
	node2->next = node3; node2->data = 2;
	node3->next = node4; node3->data = 3;
	node4->next = node3; node4->data = 4;

	LinkNode* ret = isLoop(head);
	if (ret!=NULL)
		printf("%d\n", ret->data);

	system("pause");
}
void test03(){
	LinkNode* L1 = createLink();
	LinkNode* L2 = createLink();
	LinkNode* L3 = mergeL1L2(L1, L2);
	travel(L3);
}
int main(){
	test03();
}
