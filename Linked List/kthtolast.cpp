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
ListNode * Kthtolast(ListNode * head, int k)
{
	ListNode * fast = NULL, * slow = NULL;
	fast = head;
	slow = head;
	while(fast && k)
	{
		fast = fast->next;
		k--;
	}
	while(fast && slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
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
	while(n--)
	{
		cin>>k;
		tail->next = new ListNode(k);
		tail = tail->next;
	}
	int val;
	cin>>val;
	ListNode * ans = Kthtolast(head, val);
	cout<<ans->val;
}