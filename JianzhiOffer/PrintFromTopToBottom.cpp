#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode *> queu;
    queu.push(root);
    vector<int>result;
    TreeNode *viewingNode;
    while(!queu.empty()){
        viewingNode = queu.front();
        queu.pop();
        if(!viewingNode)
            continue;
        result.push_back(viewingNode->val);
        queu.push(viewingNode->left);
        queu.push(viewingNode->right);
    }
    return result;

}