// June 2019
// William Mori

#include "movies.h"

#include <iostream>
#include <vector>
#include <string>
using std::cout;

// constructor sets up empty tree
BST::BST() : root(0) { }

// destructor deletes all nodes
BST::~BST() {
    clear(root);
    this->root = nullptr;
}

// recursive helper for destructor
void BST::clear(Node *n) {
    if (n) {
	   clear(n->left);
	   clear(n->right);
	   delete n;
    }
}

// insert value in tree; return false if duplicate
bool BST::insert(string title, double rating) {
    // handle special case of empty tree first
    if (!root) {
	   root = new Node(title, rating);
	   return true;
    }
    // otherwise use recursive helper
    return insertHelper(title, rating, root);
}

// recursive helper for insert (assumes n is never 0)
bool BST::insertHelper(string title, double rating, Node *n) {
    if (title == n->title)
	   return false;
    if (title < n->title) {
	    if (n->left)
	       return insertHelper(title, rating, n->left);
	    else {
	        n->left = new Node(title, rating);
	        n->left->parent = n;
	        return true;
	    }
    }
    else {
	    if (n->right)
	       return insertHelper(title, rating, n->right);
	    else {
	       n->right = new Node(title, rating);
	       n->right->parent = n;
	       return true;
	    }
    }
}

// print tree data pre-order
void BST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void BST::printPreOrder(Node *n) const {
    if (n) {
	n->print();
	cout << ", " << this->findDepth(n->title) << endl;
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

int BST::findDepthHelper(Node* root, string title) const {
	int depth = -1;
	Node* temp = new Node;
	temp = root;
	while (temp != NULL) {
		depth++;
		if (temp->title == title) {
			return depth;
		}
		else if (temp->title > title) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return -1;
}

int BST::findDepth(string title) const {
	return findDepthHelper(this->root, title);
}

void BST::vectorize(vector<Node*>& v, Node* root) const {
	if (root) {
		v.push_back(root);
		vectorize(v, root->left);
		vectorize(v, root->right);
    }
}

BST::Node* BST::getHR(string prefix) const {
	vector<Node*> temp;
	vector<Node*> prefixes;
	int length = prefix.length();
	this->vectorize(temp, this->root);

	for (auto i : temp) {
		if (i->title.substr(0, length) == prefix) {
			prefixes.push_back(i);
		}
	}

	Node* HR = prefixes[0];
	for (auto i : prefixes) {
		if (i->rating > HR->rating) {
			HR = i;
		}
	}
	return HR;
}

string BST::getTitle_HR(string prefix) const {
	Node* temp = getHR(prefix);
	string title = temp->title;
	return title;
}

double BST::getRating_HR(string prefix) const {
	Node* temp = getHR(prefix);
	double rating = temp->rating;
	return rating;
}


int BST::count(Node *n) const {
    if (n == nullptr) {
        return 0;
    }
    return (1 + count(n->left) + count(n->right));
}

int BST::count() const {
    return count(root);
}





















