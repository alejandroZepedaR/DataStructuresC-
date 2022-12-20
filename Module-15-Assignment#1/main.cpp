#include <iostream>
using namespace std;
//node class
class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
//binary tree type class
class BinaryTreeType{
public:

    Node* root;
    BinaryTreeType(int n){
        root = new Node(n);
    }

    //function to count nodes in binary tree
    int nodeCount(Node* n){
        if(n==NULL)return 0;
        return 1+nodeCount(n->left)+nodeCount(n->right);
    }
};

int main()
{
    //tree to test the function
	BinaryTreeType* tree = new BinaryTreeType(1);
	tree->root->left = new Node(2);
	tree->root->right = new Node(3);
	tree->root->left->left = new Node(4);
	tree->root->left->right = new Node(6);
    cout<<tree->nodeCount(tree->root);
    
	return 0;
}