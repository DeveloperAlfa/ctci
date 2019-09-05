#include<bits/stdc++.h>
using namespace std;
void ZeroMatrix(vector<vector<int>> &A)
{
	int n = A.size();
	int m = A[0].size();
	bool f1 = false, f2 = false;
	for(int i = 0; i < n; i++)
	{
		if(A[i][0]==0)
		{
			f1 = true;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(A[0][i]==0)
		{
			f2 = true;
		}
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j  <m; j++)
		{
			if(A[i][j]==0)
			{
				A[i][0] = 0;
				A[0][j] = 0;
			}
		}
	}
	for(int i = 1; i < n; i++)
	{
		if(A[i][0]==0)
		{
			for(int j = 1; j < m; j++)
			{
				A[i][j] = 0;
			}
		}
	}
	for(int i = 1; i < m; i++)
	{
		if(A[0][i]==0)
		{
			for(int j = 1; j < n; j++)
			{
				A[j][i] = 0;
			}
		}
	}
	if(f1)
	{
		for(int i = 0; i < n; i++)
		{
			A[i][0] = 0;
		}
	}
	if(f2)
	{
		for(int i = 0; i < m; i++)
		{
			A[0][i] = 0;
		}
	}
}
int main()
{
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin>>v[i][j];
	ZeroMatrix(v);
	for(int i = 0; i < n; i++) {for(int j = 0; j < m; j++) cout<<v[i][j]; cout<<endl;}

}