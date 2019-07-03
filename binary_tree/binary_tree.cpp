#include "binary_tree.h"

BinaryTreeNode* BinaryTree::creat_binary_tree(vector<int> preorder_sequence, int &index)
{
	BinaryTreeNode *node = NULL;
	int size = preorder_sequence.size();
	if (index < size && preorder_sequence[index] != null_node)
	{
		node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		node->val = preorder_sequence[index];
		
		node->left = BinaryTree::creat_binary_tree(preorder_sequence, ++index);
		node->right = BinaryTree::creat_binary_tree(preorder_sequence, ++index);
	}
	
	return node;
}

BinaryTreeNode* BinaryTree::creat_binary_tree(vector<int> &preorder_sequence)
{
	BinaryTreeNode *node = NULL;
	if (preorder_sequence.size() == 0)
		return node;

	if (preorder_sequence[0] != 999)
	{
		node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		node->val = preorder_sequence[0];
		preorder_sequence.erase(preorder_sequence.begin());

		node->left = creat_binary_tree(preorder_sequence);
		node->right = creat_binary_tree(preorder_sequence);
	}
	else
		preorder_sequence.erase(preorder_sequence.begin());

	return node;
}

void BinaryTree::pre_order(BinaryTreeNode *root)
{
	if (root)
	{
		cout << root->val << endl;
		pre_order(root->left);
		pre_order(root->right);
	}
	
}

void BinaryTree::in_order(BinaryTreeNode *root)
{
	if (root)
	{		
		in_order(root->left);
		cout << root->val << endl;
		in_order(root->right);
	}

}

void BinaryTree::post_order(BinaryTreeNode *root)
{
	if (root)
	{
		post_order(root->left);
		post_order(root->right);
		cout << root->val << endl;
	}

}

BinaryTreeNode* BinaryTree::reconstruction_by_pre_and_in(vector<int> pre, vector<int> vin)
{
	int size = pre.size();
	if (size == 0)
		return NULL;

	BinaryTreeNode* root = new BinaryTreeNode(pre[0]);

	vector<int> l_vin;
	vector<int> r_vin;
	int root_index = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (i <= root_index && vin[i] != root->val)
		{
			l_vin.push_back(vin[i]);
			root_index++;
		}
		else if (vin[i] != root->val)
			r_vin.push_back(vin[i]);
	}

	vector<int> l_pre;
	vector<int> r_pre;
	for (int i = 1; i <= size - 1; i++)
	{
		if (i <= root_index)
			l_pre.push_back(pre[i]);
		else
			r_pre.push_back(pre[i]);
	}

	root->left = reconstruction_by_pre_and_in(l_pre, l_vin);
	root->right = reconstruction_by_pre_and_in(r_pre, r_vin);

	return root;
}