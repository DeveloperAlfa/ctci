#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x)
	{
		val = x;
		next = NULL;
	}
};
void DeleteNode(ListNode * h)
{
	if(!h || !h->next) return;
	h->val = h->next->val;
	h->next = h->next->next;
}
void print(ListNode * head)
{
	ListNode * curr = NULL;
	curr = head;
	while(curr)
	{
		cout<<curr->val<<"->";
		curr = curr->next;
	}
	cout<<"X"<<endl;
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	n--;
	ListNode * head = new ListNode(k);
	ListNode * tail = head;
	while( n--)
	{
		cin>>k;
		tail->next = new ListNode(k);
		tail = tail->next;
	}
	print(head);
	DeleteNode(head->next);
	print(head);
}