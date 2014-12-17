// Elliott's Amazing Binary Tree Application!

#include <iostream>
#include <time.h>
#include "BinaryTree.h"

class Node{
public:
	Node(){}
	Node(int newdata);
	int data;
	Node *left;
	Node *right;
};

Node::Node(int newdata)
{
	data = newdata;
	left = NULL;
	right = NULL;
}

Node* insert(Node* root, int data)
{
	if (root == NULL)
	{
		root = new Node(data);
		return root;
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}
bool search(Node* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return search(root->left, data);
	}
	else
	{
		return search(root->right, data);
	}
}

int main(int argc, char* argv[]) 
{
	srand(time(NULL));
	Node* rootPtr = NULL;
	int ranNum = 0;

	for (int i = 0; i < 10; i++)
	{
		ranNum = randomNumber();
		std::cout << ranNum << std::endl;
		rootPtr = insert(rootPtr, ranNum);
	}

	int number;
	std::cout << "Enter a number to search for: " << std::endl;
	std::cin >> number;
	if (search(rootPtr, number) == true)
	{
		std::cout << "Number is in list." << std::endl;
	}
	else
	{
		std::cout << "Number not found." << std::endl;
	}
	return 0;
}

