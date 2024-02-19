#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
    
	Node(int val)
	{
		data = val;
		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}
};

// method for printing the tree formatted as a tree on the 
// console output, outputting something like this :
//          1
//        /   \
//       2     3
//      / \    / \
//     4 NULL NULL NULL
void printTree(Node* root, string indent = "", bool last = true) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "└─";
            indent += "  ";
        } else {
            cout << "├─";
            indent += "│ ";
        }
        cout << root->data << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}


int main()
{
	/*create root*/
	Node* root = new Node(1);

	/* 2 and 3 become left and right children of 1 */
	root->left = new Node(2);
	root->right = new Node(3);

	/* 4 becomes left child of 2 */
	root->left->left = new Node(4);

    root->left->left->left = new Node(5);
    root->left->left->right = new Node(6);

    printTree(root);

	return 0;
}
