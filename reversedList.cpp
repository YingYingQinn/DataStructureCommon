#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next = nullptr;
	ListNode(int val0) :val(val0){}
};

//链表反转
//非递归
ListNode* reversedList(ListNode* root)
{
	if (root == nullptr)
		return nullptr;
	ListNode* pre = nullptr;
	ListNode* p = root;
	ListNode* reversedroot = nullptr;
	while (p)
	{
		ListNode *next = p->next;
		p->next = pre;
		pre = p;
		if (next == nullptr)
			reversedroot = pre;
		p = next;
	}
	return reversedroot;
}

//递归
ListNode* reversedListdigui(ListNode* pre, ListNode* p)
{
	if (p->next == nullptr)
	{
		p->next = pre;
		return p;
	}
	ListNode* next = p->next;
	p->next = pre;
	//pre = p;
	return reversedListdigui(p, next);
}
ListNode* reversedList2(ListNode* head)
{
	if (head == nullptr)
		return head;
	return reversedListdigui(nullptr, head);
}


//链表隔一反转
ListNode* reversedListOneByOne(ListNode* head)
{
	ListNode* head0 = new ListNode(0);
	head0->next = head;
	ListNode* pre = head0;
	ListNode* p = head;
	while (p)
	{
		ListNode *next = p->next;
		if (next == nullptr)
		{
			pre->next = p;
			break;
		}
		ListNode *nextnext = next->next;
		pre->next = next;
		next->next = p;
		pre = p;
		p = nextnext;
	}
	return head0->next;
}

ListNode* reversedListOneByOne2(ListNode* p)
{
	if (p == nullptr || p->next == nullptr)
		return p;
	ListNode* pnext = p->next;
	ListNode* pnextnext = pnext->next;
	pnext->next = p;
	p->next = reversedListOneByOne2(pnextnext);
	return pnext;
}

int main()
{
	ListNode* root = new ListNode(0);
	root->next = new ListNode(1);
	root->next->next = new ListNode(2);
	ListNode* res = reversedListOneByOne2(root);
	return 0;
}