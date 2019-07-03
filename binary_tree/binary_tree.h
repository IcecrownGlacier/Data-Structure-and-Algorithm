#include <iostream>
#include <vector>
using namespace std;

const int null_node = 999;

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
	/* preorder_sequence:ABDH##I##E##CF#J##G or 1248##9##5##36#10##7 */
	BinaryTreeNode* creat_binary_tree(vector<int> preorder_sequence, int &index);

	BinaryTreeNode* creat_binary_tree(vector<int> &preorder_sequence);

	void pre_order(BinaryTreeNode *root);

	void in_order(BinaryTreeNode *root);

	void post_order(BinaryTreeNode *root);

	BinaryTreeNode* reconstruction_by_pre_and_in(vector<int> pre, vector<int> in);
};