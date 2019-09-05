#include<bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
	T * arr;
	int l, r, sz;
public:
	Stack<T>(int len)
	{
		sz = len;
		l = 0;
		r = 0;
		arr = new T[sz];
	}
	bool isEmpty()
	{
		return l==r;
	}
	bool isFull()
	{
		if(r==(l-1+sz)%sz) cout<<"Oops full stack"<<endl;
		return r==(l-1+sz)%sz;
	}
	void push(int x)
	{
		if(!isFull())
		{
			cout<<"Pushed "<<x<<endl;
			arr[r] = x;
			r = (r+1)%sz;
		}
	}
	void pop()
	{
		if(!isEmpty())
		{
			r = (r-1+sz)%sz;
			cout<<"Popped "<<arr[r]<<endl;
		}
	}
	int top()
	{
		if(!isEmpty()) 
		{
			return arr[(r-1+sz)%sz];
		}
		return -1;
	}

};
int main()
{
	Stack<int> s(20);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(1);
	s.push(2);
	s.pop();
	cout<<s.top();

}