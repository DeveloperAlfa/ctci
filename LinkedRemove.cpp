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
ListNode * LinkedRemove(ListNode * head)
{
	unordered_map<int, bool> hash;
	ListNode * curr = NULL;
	curr = head;
	while(curr && curr->next)
	{
		hash[curr->val] = true;
		if(hash[curr->next->val]) curr->next = curr->next->next;
		else curr = curr->next;
	}
	return head;
}
int main()
{
	int n;
	cin>>n;
	ListNode * head = NULL, * tail = NULL;
	int k;
	cin>>k;
	head = new ListNode(k);
	tail = head;
	n--;
	while(n--)
	{
		cin>>k;
		tail->next = new ListNode(k);
		tail = tail->next;
	}
	head = LinkedRemove(head);
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}