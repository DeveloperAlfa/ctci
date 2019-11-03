//Verdict: Accepted - devalfa

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define vsort(v) sort(v.begin(), v.end());
#define ii(a, b) make_pair(a, b)
#define endl '\n'
#define ff first
#define ss second
#define f(i, n) for(int i = 0; i < n; i++)
template <typename T>
void vtrace(string name, vector<T> v)
{
    cout<<name<<" : "<<endl;
    for(T i: v) cout<<i<<" ";
    cout<<endl;
}
template <typename T>
void trace(T count, ...)
{
    va_list list;
    va_start(list, count);
    for(int i = 1; i <= count; i++)
    {
        cout<<va_arg(list, int)<<" ";
        if((i%3)==0) cout<<endl;
    }
    cout<<endl;
    va_end(list);
}
vector<bool> make_sieve()
{
	int n = 1e6+1;
	vector<bool> sieve(n, true);
	sieve[0] = false;
	sieve[1] = false;
    for(int p = 2; p*p<1000001; p++)
    {
        if(sieve[p]) for(int i = p*p; i <= 1000001; i+=p) sieve[i] = false;
    }
	return sieve;
}
class minheap
{
	vector<int> arr;
	int sz;
	void heapify(int i)
	{
		if(i>=sz) return;
		int left = 2*i + 1;
		int right = left+1;
		if(left<sz && right<sz)
		{
			if(arr[right]<arr[i] && arr[right]<arr[left])
			{
				int temp = arr[right];
				arr[right] = arr[i];
				arr[i] = temp;
				heapify(right);
			}
			else if(arr[left]<arr[i] && arr[left]<arr[right])
			{
				int temp = arr[left];
				arr[left] = arr[i];
				arr[i] = temp;
				heapify(left);
			}
		}
		else if(left < sz && arr[left]<arr[i])
		{
			int temp = arr[left];
			arr[left] = arr[i];
			arr[i] = temp;
			heapify(left);
		}
	}
public:
	minheap()
	{
		sz = 0;
	}
	minheap(vector<int> & v)
	{
		sz = v.size();
		arr = v;
		for(int i = sz-1; i >= 0; i--)
		{
			heapify(i);
		}
	}
	int getmin()
	{
		if(sz>0) return arr[0];
		return -1;
	}
	void pop()
	{
		if(sz>0)
		{
			arr[0] = arr[sz-1];
			heapify(0);
			sz--;
		}
	}
	void push(int a)
	{
		if(arr.size()==sz)
		{
			arr.push_back(a);
		}
		else arr[sz] = a;
		

		int ch = sz, par = (sz-1)/2;
		while(par!=ch)
		{
			if(arr[par]>arr[ch])
			{
				int temp = arr[par];
				arr[par] = arr[ch];
				arr[ch] = temp;
			}
			ch = par;
			par = (ch-1)/2;
		}
		sz++;
	}
};
signed main() {
	vector<int> v = {1, 100, 99};
	minheap m(v);
	cout<<m.getmin()<<endl;
	m.pop();
	cout<<m.getmin()<<endl;
	m.pop();
	cout<<m.getmin()<<endl;
	m.pop();
	cout<<m.getmin()<<endl;
}
