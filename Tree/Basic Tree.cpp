#include<iostream>

using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	TreeNode<T>* leftNode;
	TreeNode<T>* rightNode;
	
	TreeNode(T data) {
		this->data = data;
		this->leftNode = NULL;
		this->rightNode = NULL;
	}
};

template <typename T>
class Tree {
public:
	TreeNode<T>* root;

	Tree() {
		this->root = NULL;
	}

	void add(T data, T left, T right) {
		if (root == NULL) {
			root = new TreeNode<T>(data);
			if(left != '.') root->leftNode = new TreeNode<T>(left);
			if(right != '.') root->rightNode = new TreeNode<T>(right);
		}
		else search(root, data, left, right);
	}

	void search(TreeNode<T>* root, T data, T left, T right) {
		if (root == NULL) return;// Å½»ö ½ÇÆÐ

		else if (root->data == data) {//Å½»ö ¼º°ø
			if (left != '.') root->leftNode = new TreeNode<T>(left);
			if (right != '.') root->rightNode = new TreeNode<T>(right);
		}
		else {
			search(root->leftNode, data, left, right);
			search(root->rightNode, data, left, right);
		}
	}

	void preorder(TreeNode<T>* root) {//¼ø¼­: ·çÆ®->ÁÂ->¿ì
		if (root == NULL) return;
		cout << root->data;
		if (root->leftNode != NULL) preorder(root->leftNode);
		if (root->rightNode != NULL) preorder(root->rightNode);
	}
	
	void inorder(TreeNode<T>* root) {//¼ø¼­: ÁÂ->·çÆ®->¿ì
		if (root == NULL) return;
		if (root->leftNode != NULL) inorder(root->leftNode);
		cout << root->data;
		if (root->rightNode != NULL)inorder(root->rightNode);
	}
	void postorder(TreeNode<T>* root) {//¼ø¼­: ÁÂ->¿ì->·çÆ®
		if (root == NULL) return;
		if (root->leftNode != NULL) postorder(root->leftNode);
		if (root->rightNode != NULL) postorder(root->rightNode);
		cout << root->data;
	}
};
int main() {
	Tree<char> t;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		char data, left, right;
		cin >> data >> left >> right;
		t.add(data, left, right);
	}
	t.preorder(t.root);
	cout << endl;
	t.inorder(t.root);
	cout << endl;
	t.postorder(t.root);
	cout << endl;
	system("pause");
	return 0;
}