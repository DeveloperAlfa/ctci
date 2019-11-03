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
void dfs(int start, vector<vector<int>> & adj, vector<int> & open, vector<int> & close, int & cnt)
{
	int n = 26;
	if(open[start]!=-1) return;
	open[start]  = cnt++;
	for(int i = 0; i < n; i++)
	{
		if(adj[start][i]) dfs(i, adj, open, close, cnt);
	}
	close[start] = cnt++;
}
string buildorder(vector<pair<char, char>> & edges)
{
	vector<vector<int>>  adj(26, vector<int>(26, 0));
	vector<int> open(26, -1);
	vector<int> close(26, -1);

	for(auto p: edges)
	{
		adj[p.ss-'a'][p.ff-'a'] = 1;
	}
	int cnt = 1;
	for(int i = 0; i < 26; i++)
	{
		dfs(i, adj, open, close, cnt);
	}
	set<int> chosen;
	string ans = "";
	for(int i = 0; i < 26; i++)
	{
		int less = -1, lessval = INT_MAX;
		for(int j = 0; j < 26; j++)
		{
			if(close[j]<lessval && chosen.find(j)==chosen.end())
			{
				less = j;
				lessval = close[j];
			}
		}
		chosen.insert(less);
		ans+=(char)('a'+less);
	}
	return ans;
}
signed main() {
    FIO;
	int n;
	cin>>n;
	vector<pair<char, char>>  edges;
	f(i, n)
	{
		char a, b;
		cin>>a>>b;
		edges.emplace_back(a, b);
	}
	cout<<buildorder(edges)<<endl;
}
