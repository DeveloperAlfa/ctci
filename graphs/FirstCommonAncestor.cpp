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
};
TreeNode * makeTree()
{
	int v;
	cin>>v;
	queue<TreeNode *> q;
	TreeNode * root = NULL;
	if(v!=-1)
	{
		root = new TreeNode(v);
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
struct result
{
	bool a, b;
	TreeNode * curr;
};
result FCA(TreeNode * root, int a, int b)
{
	if(root==NULL)
	{
		result ans;
		ans.a = false;
		ans.b = false;
		ans.curr = NULL;
		return ans;
	}
	result left = FCA(root->left, a, b);
	result right = FCA(root->right, a, b);
	if(left.a && left.b) return left;
	if(right.a && right.b) return right;
	result ans;
	ans.a = left.a||right.a||(root->val==a);
	ans.b = left.b||right.b||(root->val==b);
	ans.curr = root;
	return ans;
}
int main()
{
	TreeNode * root = makeTree();
	int a, b; 
	cin>>a>>b;
	result r = FCA(root, a, b);
	cout<<r.curr->val;
}