#include<bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
	T * arr;
	int l, r, sz;
public:
	Queue<T>()
	{
		sz = 2;
		arr = new T[sz];
		l = 0;
		r = 0;
	}
	bool isEmpty()
	{
		return l==r;
	}
	bool isFull()
	{
		return l==(r+1)%sz;
	}
	void expand()
	{
		T * new_array = new T[sz*2];
		int k = 0;
		for(int i = l; i != r; i = (i+1)%sz)
		{
			new_array[k++] = arr[i]; 
		}
		int * prev = arr;
		arr = new_array;
		delete[] prev;
		l = 0;
		r = sz-1;
		sz = sz*2;
	}
	void push(int x)
	{
		if(isFull()) expand();
		arr[r] = x;
		r = (r+1)%sz; 
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
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
}