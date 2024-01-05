
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include<time.h>
#include<fstream>
#include "node.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file ";
	cerr << file << ", line " << line << "." << endl;
	//abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int randNumGen(int upper, int lower)
{
	return (rand() % (upper - lower + 1)) + lower;
}

Node* create_tree_from_slides()
{
	Node* root = new Node(6);
	// root->left = new Node(2);
	// root->right = new Node(12);

	// root->left->left = new Node(-1);
	// root->left->right = new Node(4);
	// root->right->left = new Node(9);
	// root->right->right = new Node(16);

	// root->left->left->left = new Node(-3);
	// root->left->left->right = new Node(1);
	// root->left->right->left = new Node(3);
	// root->left->right->right = new Node(5);

	// root->right->left->left = new Node(8);
	// root->right->left->right = new Node(11);
	// root->right->right->left = new Node(13);
	// root->right->right->right = new Node(20);

	return root;
}

bool search(int x, Node* root)											// find a value in the tree
{
	Node* cur = root;													// create a pointer to traverse the tree
	while (true)
	{
		// See if we're still at a real node
		if (cur == nullptr)												// if the value was not found
			return false;												//    return false

		// If we found it!
		if (cur->n == x)												// if the value was found
			return true;												//    return true

		// Otherwise
		if (x < cur->n)													// if the value is less than the value in the current node
			cur = cur->left;											//    go to the left child
		else
			cur = cur->right;											//    go to the right child
	}
}

void insert(int x, Node* root)											// insert a value in the tree
{
	// Search for x in the tree
	// -If it's there, we're done.
	if (search(x, root))
		return;
	cout << x << ' ';
	// -Otherwise, search until empty subtree is reached
	//  and insert new element as root of that empty subtree
	Node* cur = root;													// start at the root
	while (true)
	{
		// Check whether where we go next is nullptr
		if (x < cur->n && cur->left == nullptr)							// if the value is less than the value in the current node and the there is no left child
		{
			cur->left = new Node(x);									//    insert the new node here
			return;
		}
		else if (x > cur->n && cur->right == nullptr)					// if the value is greater than the value in the current node and the there is no right child
		{
			cur->right = new Node(x);									//    insert the new node here
			return;
		}


		// Otherwise keep trversing the tree
		if (x < cur->n)													// if the value is less than the value in the current node
			cur = cur->left;											//    go to the left child
		else
			cur = cur->right;											//    go to the right child
	}
}

int size(Node* root)
{
	// Base case
	if (root == nullptr)
		return 0;

	// Recursive case
	return size(root->left) + size(root->right) + 1;
}

int height(Node* root)
{
	// Base case
	if (root == nullptr)
		return -1;

	// Recursive case
	// The height of a tree is:
	// the height of the taller subtree plus 1
	if (height(root->left) > height(root->right))
		return height(root->left) + 1;
	else
		return height(root->right) + 1;
}

void print_all_elements(Node* root)
{
	// Base case
	if (root == nullptr)
		return;

	// Recursive case
	print_all_elements(root->left);										// INORDER traversal
	cout << root->n << ",";
	print_all_elements(root->right);
}

void print_all_elements_pre(Node* root)
{
	// Base case
	if (root == nullptr)
		return;

	// Recursive case
	cout << root->n << ",";											// PREORDER traversal
	print_all_elements_pre(root->left);
	print_all_elements_pre(root->right);
}

void print_all_elements_post(Node* root)
{
	// Base case
	if (root == nullptr)
		return;

	// Recursive case

	print_all_elements_post(root->left);									// POSTORDER traversal
	print_all_elements_post(root->right);
	cout << root->n << ",";
}


Node* parent_search(int x, Node* root)
{
	Node* cur_parent = nullptr;
	Node* cur = root;
	while (true)
	{
		// If we found it!
		if (cur->n == x)
			return cur_parent;

		// Otherwise
		cur_parent = cur;
		if (x < cur->n)
			cur = cur->left;
		else
			cur = cur->right;
	}
}

Node* leftmost(Node* root)
{
	if (root == nullptr)
		return nullptr;

	if (root->left != nullptr)
		return leftmost(root->left);
	else
		return root;
}

void erase(int x, Node*& root)
{
	// Check whether x is in the BST
	if (!search(x, root))
		return;

	Node* parent = parent_search(x, root);								// find the parent of the node to be deleted
	bool is_left;
	Node* to_erase;
	if (parent == nullptr)												// if the node to be erased is at the ROOT of the WHOLE TREE
		to_erase = root;												//    point to_erase to root
	else if (parent->n < x)												// else if the value in parent is less than x
	{
		is_left = false;												//    the node to be erased is the right child
		to_erase = parent->right;										//    point to_erase to the right child
	}
	else
	{
		is_left = true;													//    the node to be erased is the left child
		to_erase = parent->left;										//    point to_erase to the left child
	}

	// Case 1: x's node is a leaf
	if (to_erase->left == nullptr && to_erase->right == nullptr)		// if both children of to_erase are NULL (the node is a leaf)
	{
		delete to_erase;												// delete the node pointed by to_erase
		if (parent == nullptr)											// if this is the only node in the tree
			root = nullptr;												//    set root to NULL
		else if (is_left)												// else if the node deleted is a left child of parent
			parent->left = nullptr;									//    set parent's left pointer to NULL
		else
			parent->right = nullptr;								//    set parent's right pointer to NULL
		return;
	}

	// Case 2: x's node is not a leaf and 
	// next-largest value in the BST is a leaf.
	Node* leftmost_in_right_st = leftmost(to_erase->right);				// find the LEFTMOST node in the RIGHT subtree
	if (leftmost_in_right_st != nullptr 								// if this node is a leaf (it is not NULL and both its children are NULL)
		&& leftmost_in_right_st->left == nullptr && leftmost_in_right_st->right == nullptr)
	{
		Node* parent = parent_search(leftmost_in_right_st->n, root);	//    find the parent of the node that will be actually removed
		if (parent->n < leftmost_in_right_st->n)						//    if the parent's value is less than the value in the lefmost node (the node to be erased is the parent of the leftmost)
			parent->right = nullptr;									//       set parent's right pointer to NULL
		else
			parent->left = nullptr;										//       set parent's left pointer to NULL (the node to be erased is separated from the leftmost by one or more nodes)
		to_erase->n = leftmost_in_right_st->n;							//    replace the value in the node to be erased with the value in the node actually erased (leftmost in right subtree)
		delete leftmost_in_right_st;									//    remove the leftmost node
		return;
	}

	// Case 3: x's node is not a leaf and both
	// adjacent nodes in the BST are not leaves (they have a child or they don't exist). 
	else
	{
		if (leftmost_in_right_st == nullptr)							// there is no right child, work with the left subtree 
		{
			if (parent == nullptr)										// if the node to be actually removed is the ROOT of the WHOLE TREE
				root = to_erase->left;									//    point root to the left child of the node to be erased
			else if (parent->n < to_erase->n)							// else if the parent's value is less than the value in the node to be erased
				parent->right = to_erase->left;							//    set the right pointer of the parent to the left child of its child (left grandchild)
			else
				parent->left = to_erase->left;							//    set the left pointer of the parent to the left child of its child (left grandchild)
			delete to_erase;											// delete the node
		}
		else															// there is a right child and it is not a leaf
		{
			Node* parent = parent_search(leftmost_in_right_st->n, root);// find the parent of the leftmost node in the right subtree
			if (parent == to_erase)										// if the parent is the node to be actually removed
				to_erase->right = leftmost_in_right_st->right;			//    set the right pointer of the node to be erased to the right child of the leftmost node
			else if (parent->n < leftmost_in_right_st->n)				// else if the parent's value is less than the value in the leftmost node
				parent->right = leftmost_in_right_st->left;				//    set the parent's right pointer to the left child of the leftmost node
			else
				parent->left = leftmost_in_right_st->right;				//    set the parent's left pointer to the right child of the leftmost node
			to_erase->n = leftmost_in_right_st->n;						// replace the value in the node to be erased with the value in the node actually erased (leftmost in right subtree) 
			delete leftmost_in_right_st;								// delete the node
		}
		return;
	}
}

void erase_all_elements(Node*& root)
{
	// Base case
	if (root == nullptr)
		return;

	// Recursive case
	erase_all_elements(root->left);		// POSTORDER traversal
	erase_all_elements(root->right);
	delete root;
	root = nullptr;
}

void print(Node* p, int depth)
{
	if (p != NULL)
	{
		print(p->right, depth + 1);
		cout << setw(4 * depth) << ""; // Indent 4*depth spaces.
		cout << setw(3) << p->n << endl;
		print(p->left, depth + 1);
	}
}

Node* create_tree()
{
	int max;
	srand(static_cast<int> (time(NULL)));
	cout << "Enter size of tree (min. 1): ";
	cin >> max;
	Node* root = new Node(randNumGen(99, 1));
	cout << root->n << ' ';
	while (size(root) < max)
	{
		insert(randNumGen(99, 1), root);
	}
	return root;
}

Node* create_tree_from_file()
{
	ifstream inFile;
	inFile.open("input_bst.txt");
	int value;
	srand(static_cast<int> (time(NULL)));
	cout << "Values inserted in the tree: ";
	inFile >> value;
	Node* root = new Node(value);
	cout << root->n << ' ';
	while(inFile)
	{
		inFile >> value;
		insert(value, root);
	}
	inFile.close();
	return root;
}


int main()
{
	int x;
	char op;

	while (true)
	{
		Node* root = create_tree_from_slides();
		//Node* root = create_tree_from_file();
		// Node* root = create_tree();
		do
		{
			cout << endl << endl;
			cout << "Tree Size: " << size(root) << endl;
			cout << "Tree Height: " << height(root) << endl; // << endl << endl;

			if (root != nullptr)
				cout << "root: " << root->n << endl << endl;
			else
				break;
			cout << endl << endl;
			print(root, 0);
			cout << endl << endl;

			cout << "Enter operation[(i)nsert),(e)rase, i(n)-order, p(r)e-order, p(o)st-order, (x)it]: ";
			cin >> op;
			if (op == 'x')
				break;
			else if (op == 'i')
			{
				cout << "Enter value to insert: ";
				cin >> x;
				insert(x, root);
			}
			else if (op == 'e')
			{
				cout << "Enter value to erase: ";
				cin >> x;
				erase(x, root);
			}
			else if (op == 'n')
			{
				cout << endl << "Inorder traversal: ";
				print_all_elements(root);
				cout << endl;
			}
			else if (op == 'r')
			{
				cout << endl << "Preorder traversal: ";
				print_all_elements_pre(root);
				cout << endl;
			}
			else if (op == 'o')
			{
				cout << endl << "Postorder traversal: ";
				print_all_elements_post(root);
				cout << endl;
			}
		} while (true);
		cout << endl;
		if (size(root) == 0)
			cout << "Tree is empty, starting again!" << endl << endl;
		else
		{
			print(root, 0);
			erase_all_elements(root);
			if (size(root) == 0)
			{
				cout << "All nodes were now removed" << endl;
				break;
			}
		}
	}
	return 0;
}

/*
Node* create_tree_from_slides()
{
	Node* root = new Node(6);
	root->left = new Node(2);
	root->right = new Node(12);

	root->left->left = new Node(-1);
	root->left->right = new Node(4);
	root->right->left = new Node(9);
	root->right->right = new Node(16);

	root->left->left->left = new Node(-3);
	root->left->left->right = new Node(1);
	root->left->right->left = new Node(3);
	root->left->right->right = new Node(5);

	root->right->left->left = new Node(8);
	root->right->left->right = new Node(11);
	root->right->right->left = new Node(13);
	root->right->right->right = new Node(20);

	return root;
}

38 80 19 64 17 29 26 62 34 41 11 91 50 20 69  balanced

25 66 48 83 76 16 52 9 96 40 13 62 47 34 49   > right subtree

83 32 26 73 28 61 66 94 99 45 46 30 77 14 15  > left subtree




*/