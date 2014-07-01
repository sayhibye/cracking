#include<iostream>
#include<stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(Null){}
};

class Solution{
public:
	vector<int> preOrder(TreeNode *root)
	{
		vector<int> result;
		if(root!=NULL)
		{
			
			stack<TreeNode *> s;

			TreeNode *p=root;
			while(!s.empty() || p!=NULL)
			{
				if(p!=NULL)
				{
					s.push(p);
					result.push_back(p->val);
					p=p->left;
				}

				else
				{
					p=s.top();
					s.pop();
					p=p->right;
				}
			}
			
		}
		return result;
	}

};