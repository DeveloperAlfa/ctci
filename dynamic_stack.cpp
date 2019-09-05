#include<bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
	T * arr;
	int l, r, sz;
public:
	Stack<T>()
	{
		sz = 1;
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
		return r==sz;
	}
	void expand()
	{
		cout<<"Expanding"<<endl;
		T * new_arr = new T[sz*2];
		for(int i = 0; i < sz; i++)
		{
			new_arr[i] = arr[i];
		}
		int * prev = arr;
		arr = new_arr;
		delete[] prev;
		l = 0;
		r = sz;
		sz = sz*2;
	}
	void push(int x)
	{
		if(isFull()) expand();
		arr[r++] = x;
	}
	void pop()
	{
		if(!isEmpty()) r--;
	}
	int top()
	{
		if(!isEmpty()) return arr[r-1];
		return -1;
	}
};
int main()
{
	Stack<int> s;
	s.push(10);
	s.push(2);
	s.pop();
	cout<<s.top();
}