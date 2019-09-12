#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x)
	{
		val = x;
		left = NULL;
		right = NULL;
	}
}
TreeNode * makeTree()
{
	int v;
	cin>>v;
	queue<TreeNode *> q;
	if(v!=-1)
	{
		TreeNode * root = new TreeNode(v);
		q.push(root);
	}
	else return NULL;
	while(!q.empty())
	{
		TreeNode * curr = q.front();
		q.pop();
		int a, b;
		cin>>a>>b;
		if(a!=-1)
		{
			TreeNode * left = new TreeNode(a);
			curr->left = left;
			q.push(left);
		}
		if(b!=-1)
		{
			TreeNode * right = new TreeNode(b);
			curr->right = right;
			q.push(right);
		}
	}
	return root;
}
	
int main()
{
	TreeNode * root = makeTree();

}