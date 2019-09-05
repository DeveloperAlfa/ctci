#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &A)
{
	int n = A.size();
	int l = 0, r = n-1, row = 0;
	while(l<=r)
	{
		for(int i = l; i < r; i++)
		{
			int a1 = row, b1 = i;
			int a2 = b1, b2 = n-1-a1;
			int a3 = b2, b3 = n-1-a2;
			int a4 = b3, b4 = n-1-a3;
			int temp = A[a1][b1];
			A[a1][b1] = A[a4][b4];
			A[a4][b4] = A[a3][b3];
			A[a3][b3] = A[a2][b2];
			A[a2][b2] = temp;
		}
		l++;
		r--;
		row++;
	}
}
int main()
{
	
	int n;
	cin>>n;
	vector<vector<int>> A(n, vector<int>(n, 0));
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			A[i][j] = k++;
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	rotate(A);
	cout<<"Rotated:"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

}