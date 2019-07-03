#include "binary_tree.h"

int main()
{
	vector<int> preorder_sequence = { 1, 2, 4, null_node, null_node,
		null_node, 3, null_node, 5 };

	vector<int> preorder_sequence1 = { 1, 2, 4, 8, null_node, null_node,
		9, null_node, null_node, 5, null_node, null_node, 3, 6, null_node,
		10, null_node, null_node, 7 };

	int index = 0;
	BinaryTree *binary_tree = new BinaryTree();
	BinaryTreeNode *binary_tree_root = binary_tree->creat_binary_tree(preorder_sequence1);

	binary_tree->pre_order(binary_tree_root);
	cout << endl;
	binary_tree->in_order(binary_tree_root);
	cout << endl;
	binary_tree->post_order(binary_tree_root);

	system("pause");
	return 0;
}