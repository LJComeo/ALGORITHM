#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

vector<int> EveryLevel(TreeNode * root)
{
	vector<int> ret;
	if (root == nullptr)
	{
		return ret;
	}
	queue<TreeNode *> qt;
	TreeNode * cur;
	qt.push(root);
	while (!qt.empty())
	{
		cur = qt.front();
		ret.push_back(cur->val);

		if (cur->left)
			qt.push(cur->left);
		if (cur->right)
			qt.push(cur->right);
		qt.pop();

	}
}

int main()
{

	return 0;
}