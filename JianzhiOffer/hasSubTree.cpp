#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot2==nullptr)
        return true;
    if(pRoot1==nullptr)
        return false;
    return IsSubTree(pRoot1->left,pRoot2->left)&&IsSubTree(pRoot1->right,pRoot2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot1==nullptr||pRoot2==nullptr)
        return false;
    return IsSubTree(pRoot1,pRoot2)||
    HasSubtree(pRoot1->left,pRoot2)||
    HasSubtree(pRoot1->right,pRoot2);
}