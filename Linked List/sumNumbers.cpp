//I have the fire now
//Welcome to this template and probably an accepted solution by developeralfa, devalfa or his team :)
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define fl(i, s, n, k) for(lli i = s; i < n; i+=k)
#define grid(m,n,v,k) vector<vector<lli>> v(m, vector<lli>(n, k))
#define sortvc(v, c) sort(v.begin(), v.end(), c);
#define sortv(v) sort(v.begin(), v.end());
#define ii(a, b) make_pair(a, b)
#define pll pair<lli, lli>
#define llinput(k) lli k; cin>>k;
#define endl '\n'
#define ff first
#define ss second
#define f(i, n) for(int i = 0; i < n; i++)
bool paircomp(pll l, pll r)
{
    if(l.ff==r.ff) return l.ss<r.ss;
    return l.ff<r.ff;
}
template <typename T>
void vtrace(string name, vector<T> v)
{
    cout<<name<<" : "<<endl;
    for(T i: v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
void vptrace(string name, vector<pll> v)
{
    cout<<name<<" : "<<endl;
    for(pll i: v)
    {
        cout<<"<"<<i.ff<<", "<<i.ss<<"> ";
    }
    cout<<endl;
}

template <typename T>
void trace(T count, ...)
{
    va_list list;
    va_start(list, count);
    for(int i = 1; i <= count; i++)
    {
        cout<<i<<" : "<<va_arg(list, int)<<" |||| ";
        if((i%4)==0) cout<<endl;
    }
    cout<<endl<<"------------------ end of list ------------------"<<endl;
    va_end(list);
}
int bin_largest_smaller(vector<lli> vec, lli x, bool eq)
{
    int start = 0, end = vec.size(), ans = -1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(vec[mid]==x && eq) return mid;
        else if(vec[mid]<x)
        {
            if(ans==-1||vec[ans]<vec[mid]) ans = mid;
            start = mid+1;
        }
        else end = mid-1;
    }
    return ans;
}
int bin_smallest_larger(vector<lli> vec, lli x, bool eq)
{
    int start = 0, end = vec.size(), ans = -1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(vec[mid]==x && eq) return mid;
        else if(vec[mid]<=x)
        {
            start = mid+1;
        }
        else
        {
            if(ans==-1||vec[ans]>vec[mid]) ans = mid;
             end = mid-1;
        }
    }
    return ans;
}

void make_sieve(vector<bool> &sieve)
{
    for(int p = 2; p*p<1000001; p++)
    {
        if(sieve[p])
        {
            for(int i = p*p; i <= 1000001; i+=p)
            {
                sieve[i] = false;
            }
        }
    }
}
void solve(vector<lli> &arr, int n)
{
}

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
int sum(int a, int b, int c)
{
	return (a+b+c)%10;
}
int carry(int a, int b, int c)
{
	return (a+b+c)%10;
}
ListNode * addBackward(ListNode * n1, ListNode * n2)
{
	ListNode * head1 = NULL, * head2 = NULL;
	int c = 0;
	while(n1&&n2)
	{
		int a = n1->val;
		int b = n2->val;
		if(head1==NULL)
		{
			head1 = new ListNode(sum(a, b, c));
			tail1 = head1;
		}
		else
		{
			tail1->next = new ListNode(sum(a, b, c));
			tail1 = tail1->next;
		}
		c = carry(a, b, c);
		n1 = n1->next;
		n2 = n2->next;
	}
	while(n1)
	{
		int a = n1->val;
		if(head1==NULL)
		{
			head1 = new ListNode(sum(a, 0, c));
			tail1 = head1;
			n1 = n1->next;
		}
		else
		{
			tail1->next = new ListNode(sum(a, 0, c));
			tail1 = tail1->next;
			n1 = n1->next;
		}
		c = carry(a, 0, c);
	}
	while(n2)
	{
		int b = n2->val;
		if(head1==NULL)
		{
			head1 = new ListNode(sum(0, b, c));
			tail1 = head1;
			n2 = n2->next;
		}
		else
		{
			tail1->next = new ListNode(sum(0, b, c));
			tail1 = tail1->next;
			n2 = n2->next;
		}
		c = carry(0, b, c);
	}
	if(c!=0)
	{
		tail1->next = new ListNode(1);
	}
	return head1;
}
int main() {
    FIO   
    //vector<bool> sieve(1000001, true);
    //make_sieve(sieve);
	llinput(n);
	vector<lli> arr(n, 0);
	f(i, n) cin>>arr[i];
    solve(arr, n);
}
