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
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int a)
	{
		val = a;
		left = NULL;
		right = NULL;
	}
};
TreeNode * makeBST(int * arr, int l,int r)
{
	if(l>r) return NULL;
	int mid = l + (r-l)/2;
	TreeNode * ans = new TreeNode(arr[mid]);
	ans->left = makeBST(arr, l, mid-1);
	ans->right = makeBST(arr, mid+1, r);
	return ans;
}
int offset = 0;
void inorder(TreeNode * root)
{
	if(root==NULL) return;
	cout<<"l";
	inorder(root->left);
	//for(int i = 0; i < offset; i++) cout<<" ";
	cout<<root->val<<endl;
	cout<<"r";
	offset++;
	inorder(root->right);
	offset--;	
}
int main() {
    FIO   
	int n;
	cin>>n;
	int * arr = new int[n];
	f(i, n) cin>>arr[i];
	inorder(makeBST(arr, 0, n-1));

}
