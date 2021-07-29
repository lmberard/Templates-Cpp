
#include <vector>
#include <iostream>
using namespace std;


struct Node{
	char data;
	Node *left;
	Node *right;
};

void preorder(struct Node *root)
{
	if(root == NULL)
		return;
	cout<< root->data;
	preorder(root->left);
	preorder(root->right);
}


int main(void)
{

}