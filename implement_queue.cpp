#include<bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
	T * arr;
	int l, r, sz;
public:
	Queue<T>(int len)
	{
		arr = new T[len];
		sz = len;
		r = 0;
		l = 0;
	}
	bool isFull()
	{
		return r==(l-1+sz)%sz;
	}
	bool isEmpty()
	{
		return r==l;
	}
	void push(int x)
	{
		if(!isFull())
		{
			arr[r] = x;
			r = (r+1)%sz;
		}
	}
	void pop()
	{
		if(!isEmpty())
		{
			l = (l+1)%sz;
		}
	}
	T front()
	{
		if(!isEmpty()) return arr[l];
		return 0;
	}
};
int main()
{
	Queue<char> q(10);
	q.push('a');
	q.push('d');
	cout<<q.front();
	q.pop();
	cout<<q.front(); 
}