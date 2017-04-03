
#include <fstream>
#include <iostream>

using namespace std;

template <class T>
class Tree
{
private:
	struct Node

	{
		friend class B_tree;

		T value_;
		Node *left;
		Node *right;
		Node() {};
		Node(const T value) : value_(value) { }
		~Node() {}
		void show(ostream &out, const int level = 0) const;
	};

	Node *tree, *null_tr;
	void null_tree(Node *tr_)
	{
		if (!tr_) return;
		if (tr_->left)
		{
			null_tree(tr_->left);
			tr_->left =nullptr;
		}
		if (tr_->right)
		{
			null_tree(tr_->right);
			tr_->right =nullptr;
		}
		delete tr_;
	}
	
public:
	Tree()
	{
		tree = NULL;
		null_tr = nullptr;
	};
	Node* tree_one() { return tree };
	void file_tree(char* name);
	void add(const T value);
	bool find(const T value);
	bool isEmpty() const { return tree== NULL; }
	void print(ostream &out) const;
	~Tree() 
	{
		null_tree(tree);
		null_tree(null_tr);
	};
};
