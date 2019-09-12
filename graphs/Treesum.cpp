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
int countPossible(TreeNode * root, unordered_map<int, int> &umap, int pref, int target)
{
	if(root==NULL)
	{
		if(target==0)
		{
			return 1;
		}
		return 0;
	}
	int val = pref + root->val;
	int ans = umap[val-target];
	umap[val]++;
	//cout<<"val:"<<val;
	ans+=countPossible(root->left, umap, val, target);
	ans+=countPossible(root->right, umap, val, target);
	//cout<<", ans:"<<ans<<endl;
	umap[val]--;
	return ans;
}
int main()
{
	TreeNode * root = makeTree();
	int sum = 0;
	cin>>sum;
	unordered_map<int, int> umap;
	umap[0] = 1;
	cout<<countPossible(root, umap, 0, sum);

}