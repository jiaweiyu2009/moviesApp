// June 2019
// William Mori

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <vector>

using namespace std;

class BST {

 public:

    BST();                   
    ~BST();                  
    bool insert(string title, double rating);     
    void printPreOrder() const;    
    int findDepth(string title) const;  
    string getTitle_HR(string prefix) const;
    double getRating_HR(string prefix) const;
    int count() const;
    


 private:

    struct Node {

	string title;
	double rating;
	Node *left, *right, * parent;
	
    Node(string t="", double r=0) : title(t), rating(r), left(0), right(0), parent(0) { }

    void print() { cout << this->title << ", " << this->rating; }

    };

    Node *root;

    void clear(Node *n); // for destructor
    bool insertHelper(string title, double rating, Node *n); 
    void printPreOrder(Node *n) const;
    int findDepthHelper(Node* root, string title) const;
    void vectorize(vector<Node*>& v, Node* root) const;
    Node* getHR(string prefix) const;
    int count(Node* n) const;

};

#endif































































































/*
#ifndef MOVIES_H
#define MOVIES_H

#include <vector>
#include <iostream>
using namespace std;


class BST {

private:

	struct Node {

	string title;
	double rating;
	Node* parent;
	Node* right;
	Node* left;

	Node() {}

	Node(string title, double rating) {
		this->title = title;
		this->rating = rating;
		parent = 0;
		left = 0;
		right = 0;
	}

	void print() const {
		cout << "{" << this->title << ", " << this->rating << "}" << endl;
	}

};

	Node* root;

	//void insertHelper(Node* root, string title, double rating);
	bool removeHelper(Node* parent, Node* target, string title);
	Node* searchHelper(Node* root, string title) const;
	void searchPrefixHelper(Node* root, string prefix) const;
	vector<Node*> searchPrefixHR_Helper(Node* root, string prefix) const;
	void printHelper(Node* root) const;
	bool insert(string title, double rating, Node* n);

public:

	//void insert(string title, double rating);
	bool insert(string title, double rating);
	bool remove(string title);
	Node* search(string title) const;
	void searchPrefix(string prefix) const;
	Node* searchPrefixHR(string prefix) const;
	void print() const;

};

#endif

*/

